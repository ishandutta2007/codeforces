/**
 * June 2012 Codechef Long Contest
 *
 * Problem:     MATCH
 * Author:      Anton Lunyov (Tester)
 * Complexity:  O(S * 2^N * N + M * 2^N * S), where S defined below
 * Timing:      0.03 out of 3
 *
 * Description:
 * Recall that we have two sets of vertexes U with |U|=n<=6
 * and V that can be quite large. We call subsets of vertexes in U by masks.
 * We scan vertexes in V one by one. At each moment we should know
 * what probability has each possible graph. But since we care only about
 * value of maximum matching we unite all graphs in several groups.
 * Namely the only thing that we should know is what masks satisfy Hall lemma
 * in the current graph. Mask T satisfies Hall lemma if
 * for each submask S of T we have |ADJ(S)|>=|S|
 * where ADJ(S) is the set of vertexes from V of the graph
 * that are adjacent to some vertex of S. We store this set of masks
 * as a "supermask" of length 2^n (since n<=6 we can use 64bit integer type).
 * Such supermasks will be our DP states.
 * Surprisingly but there is relatively small number of such states.
 */

#include <cstdio>
#include <bitset>
using namespace std;

typedef unsigned long long ULL;
//typedef __uint128_t u128;
//typedef __uint128_t u128;
#define next nxttt
#define prev prv
typedef bitset<128> u128;
typedef long long ll;
const ll mod=1000000007;
u128 zero;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

inline int bit(int n) {
    return 1 << n;
}

inline u128 bitu128(int n) {
	u128 p=zero; p[n]=1;
	return p;
}

const int maxN = 7; // this solution is so fast that can handle n=6 easily
const int max2N = 1 << maxN;
const int maxM = 100;

const int maxS = 64184; // the number of DP states for n=6

// sizes[i] = NextPrime[2 * len[i]]
// where len[i] is the number of DP states for n=i
// It is used as the size of hash table when n=i
const int sizes[maxN + 1] = {0, 5, 11, 37, 137, 821, 7529, 164184};
const int maxSZ = 164184; // the maximum size for hash table

// "bfs" is the queue of DP states traversed in some convenient order
// but it is not real queue; we do not erase old states
// "len" is the current number of states in "bfs"
// After precalc "len" is equal to the total number of DP states
int len;
u128 bfs[maxS];

// hash table for efficient finding whether the DP state is new
int SZ; // size of hash table

// "what[i]" is some DP state; they are stored in quite random order here
u128 what[maxSZ];

// bfs[ind[i]] = what[i]
// So "ind[i]" is the index of DP state "what[i]" in "bfs" array
int ind[maxSZ];

// return the index of DP state "state" in the array "bfs"
// if this state is new then insert it to the hash table and to the array "bfs"
int get_ind(u128 state) {
    // position where we try to insert "state"
    int pos=0;
    for (int i=0;i<128;i++) {
    	pos=(pos*2+state[i])%SZ;
    }
    //int pos = state % SZ;
    while (true) {
        // if "state" has already been before we break
        if (what[pos] == state) {
            break;
        }
        if (what[pos] == 0) {
            what[pos] = state;
            bfs[len] = state;
            ind[pos] = len;
            ++len;
            return len-1;
        }
        
        ++pos;
        if (pos==SZ) {
            pos = 0;
        }
    }
    // in the end "what[pos]" is always equal to "state"
    // so "ind[pos]" is correct index of "state" in "bfs"
    return ind[pos];
}

// next[mask][k] is the index of DP state (in "bfs" array)
// that we obtain from the DP state "bfs[k]"
// when we add a new vertex v from V such that ADJ(v) = mask to the graph
int next[max2N][maxS];

// match[k] is the size of maximum matching of DP state "bfs[k]"
int match[maxS];

void precalc(int n) {
    int N = bit(n);

    u128 fixed_size[maxN + 1] = {0};
    for (int mask = 0; mask < N; ++mask)
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & bit(i)) { 
                cnt++;
            }
        }
        // "cnt" is now the number of 
        fixed_size[cnt] |= bitu128(mask);
    }

    // initialization of hash table and "bfs" array
    SZ = sizes[n];
    for (int k = 0; k < SZ; ++k) {
        what[k] = 0;
    }
    len=0;

    // state = 1 represents empty graph
    get_ind(1);

    for (int k = 0; k < len; ++k) {
        // our current state
        u128 state = bfs[k];

        // pred_hall[i] is the supermask of masks
        // that will satisfy Hall lemma condition if we add edge (U[i],v)
        // to the graph with the given DP state
        // (with possible exclusion of some masks from the current "state")
        // One can see that pred_hall[i] can be obtained
        // by including vertex "i" to each "mask" of the "state"
        u128 pred_hall[maxN] = {0};
        for (int mask = 0; mask < N; ++mask) {
            if ((state & bitu128(mask)).any()) {
                for (int i = 0; i < n; ++i) {
                    pred_hall[i] |= bitu128(mask | bit(i));
                }
            }
        }

        // looping through all possible masks
        for (int mask = 0; mask < N; ++mask) {
            // "nxt" is the DP state that we obtain
            // after adding edges (U[i],v) for all "i" in "mask"
            // to the graph that has DP state "state"
            // One can see that this state is the union of all states that
            // will be obtained by adding each of the edge separately
            u128 nxt = state;
            for (int i = 0; i < n; ++i) {
                if (mask & bit(i)) {
                    nxt |= pred_hall[i];
                }
            }

            // we call "get_ind" that make all needed things with "nxt":
            // check whether it is the new DP state, add it to the "bfs" if yes
            // and return its index in "bfs" in both cases
            next[mask][k] = get_ind(nxt);
        }
        for (int i = n; i >= 0; --i) {
            if ((state & fixed_size[i]).any()) {
                match[k]=i;
                break;
            }
        }
    }
 //   printf("%d\n",len);
}

ll p[maxN][maxM]; // probability adjacent matrix
ll prev[maxS]; // previous row of DP values
ll cur[maxS]; // current row of DP values

ll expectedMaximumMatching(int n, int m) {
    // initialization of "prev"
    prev[0]=1;
    for (int k=1;k<len;k++) {
        prev[k] = 0;
    }

    int N = bit(n);
    // looping though all vertexes of V
    for (int j = 0; j < m; ++j) {
        // initialization of "cur"
        for (int k = 0; k < len; ++k) {
            cur[k] = 0;
        }

        // looping through all possible masks = ADJ(V[j])
        for (int mask = 0; mask < N; ++mask) {
            // "prob" is the probability that ADJ(V[j]) = mask
            ll prob = 1;
            for (int i = 0; i < n; ++i) {
                prob = (prob*(mask & bit(i) ? p[i][j] : mod+1 - p[i][j]))%mod;
            }

            // if we were previously in the state "bfs[k]"
            // then adding all edges (U[i],V[j]) for all "i" from "mask"
            // will bring us to the DP state with index "next[mask][k]"
            for (int k = 0; k < len; ++k)
                cur[next[mask][k]] = (cur[next[mask][k]]+prob * prev[k])%mod;
        }

        // copying of "prev" to "cur"
        for (int k = 0; k < len; ++k) {
            // We need this in order to avoid dealing with numbers
            // less than 1e-308. This can be several times slower
            // than with usual numbers. There was a discussion of this effect
            // at Codeforces after some TopCoder SRM.
            prev[k] = cur[k];
        }
    }

    // calcultating the answer
    ll ans = 0;
    for (int k = 0; k < len; ++k) {
//    	printf("%d %lld\n",k,prev[k]);
    	if (match[k]==n) ans=(ans+prev[k])%mod;
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d", &n); m=n;

    precalc(n);


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%lld", &p[i][j]);
            p[i][j]=p[i][j]*powmod(100,mod-2)%mod;
        }
    }

    ll ans = expectedMaximumMatching(n, m);
    printf("%lld\n", ans);

    return 0;
}