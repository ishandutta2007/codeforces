// C++ program for implementation of Aho Corasick algorithm
// for string matching
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
#include <set>
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
typedef long long ll;
// Max number of states in the matching machine.
// Should be equal to the sum of the length of all keywords.
const int MAXS = 204;
 
// Maximum number of characters in input alphabet
const int MAXC = 26;
 
// OUTPUT FUNCTION IS IMPLEMENTED USING out[]
// Bit i in this mask is one if the word with index i
// appears when the machine enters this state.
set<int> out[MAXS];
ll ov[MAXS];
// FAILURE FUNCTION IS IMPLEMENTED USING f[]
ll f[MAXS];
 
// GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING g[][]
ll g[MAXS][MAXC];
 
// Builds the string matching machine.
// arr -   array of words. The index of each keyword is important:
//         "out[state] & (1 << i)" is > 0 if we just found word[i]
//         in the text.
// Returns the number of states that the built machine has.
// States are numbered 0 up to the return value - 1, inclusive.
int buildMatchingMachine(string arr[], int k)
{
    // Initialize all values in goto function as -1.
    for (ll i=0;i<MAXS;i++) for (ll j=0;j<MAXC;j++) g[i][j]=-1;
 
    // Initially, we just have the 0 state
    int states = 1;
 
    // Construct values for goto function, i.e., fill g[][]
    // This is same as building a Trie for arr[]
    for (int i = 0; i < k; ++i)
    {
        const string &word = arr[i];
        int currentState = 0;
 
        // Insert all characters of current word in arr[]
        for (int j = 0; j < word.size(); ++j)
        {
            int ch = word[j] - 'a';
 
            // Allocate a new node (create a new state) if a
            // node for ch doesn't exist.
            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;
 
            currentState = g[currentState][ch];
        }
 
        // Add current word in output function
        out[currentState].insert(i);
    }
 
    // For all characters which don't have an edge from
    // root (or state 0) in Trie, add a goto edge to state
    // 0 itself
    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;
 
    // Now, let's build the failure function
 
    // Initialize values in fail function
    for (ll i=0;i<MAXS;i++) f[i]=-1;
 
    // Failure function is computed in breadth first order
    // using a queue
    queue<int> q;
 
     // Iterate over every possible input
    for (int ch = 0; ch < MAXC; ++ch)
    {
        // All nodes of depth 1 have failure function value
        // as 0. For example, in above diagram we move to 0
        // from states 1 and 3.
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }
 
    // Now queue has states 1 and 3
    while (q.size())
    {
        // Remove the front state from queue
        int state = q.front();
        q.pop();
 
        // For the removed state, find failure function for
        // all those characters for which goto function is
        // not defined.
        for (int ch = 0; ch < MAXC; ++ch)
        {
            // If goto function is defined for character 'ch'
            // and 'state'
            if (g[state][ch] != -1)
            {
                // Find failure state of removed state
                int failure = f[state];
 
                // Find the deepest node labeled by proper
                // suffix of string from root to current
                // state.
                while (g[failure][ch] == -1)
                      failure = f[failure];
 
                failure = g[failure][ch];
                f[g[state][ch]] = failure;
 
                // Merge output values
                for (auto &w:out[failure]) out[g[state][ch]].insert(w);
 
                // Insert the next level node (of Trie) in Queue
                q.push(g[state][ch]);
            }
        }
    }
 
    return states;
}
 
// Returns the next state the machine will transition to using goto
// and failure functions.
// currentState - The current state of the machine. Must be between
//                0 and the number of states - 1, inclusive.
// nextInput - The next character that enters into the machine.
int findNextState(int currentState, char nextInput)
{
    int answer = currentState;
    int ch = nextInput - 'a';
 
    // If goto is not defined, use failure function
    while (g[answer][ch] == -1)
        answer = f[answer];
 
    return g[answer][ch];
}

typedef vector<ll> vi;
typedef vector<vi> vvi;
const ll INF=1e17;
vvi matrixMul(const vvi &a, const vvi &b) {
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    vvi res(n, vi(k));
    for (ll i=0;i<n;i++) for (ll j=0;j<k;j++) res[i][j]=-INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int p = 0; p < m; p++)
                chkmax(res[i][j], a[i][p]+b[p][j]);
    return res;
}

vvi matrixPow(const vvi &a, ll p) {
    assert(p>0);
    if (p == 1)
        return a;
    if (p & 1)
        return matrixMul(a, matrixPow(a, p - 1));
    return matrixPow(matrixMul(a, a), p / 2);
}

string ss[204];
ll sv[204];
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,l; cin>>n>>l;
    for (ll i=0;i<n;i++) cin>>sv[i];
    for (ll i=0;i<n;i++) cin>>ss[i];
    ll sn=buildMatchingMachine(ss, n);
    for (ll i=0;i<sn;i++) {
        ov[i]=0;
        for (auto &w:out[i]) ov[i]+=sv[w];
    }
    vvi mat(sn, vi(sn));
    for (ll i=0;i<sn;i++) for (ll j=0;j<sn;j++) mat[i][j]=-INF;
    for (ll i=0;i<sn;i++) {
        for (ll c=0;c<26;c++) {
            char ch=c+'a';
            ll j=findNextState(i,ch);
            chkmax(mat[i][j],ov[j]);
        }
    }
    ll ans=0;
    vvi res=matrixPow(mat,l);
    for (ll j=0;j<sn;j++) {
        chkmax(ans,res[0][j]);
    }
    cout<<ans<<endl;
}