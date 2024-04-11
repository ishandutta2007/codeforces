#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define pii pair <int, int>
#define XX first
#define YY second

// constants:
const int mn = 200005;
const int mod = 1000000007;
const long long inf = 4444444444444444444;
const int sminf = 1111111111;
const bool is_multitest = 1;
const bool is_interactive = 0;

// i/o methods:
const bool input_from_file = 0;
const bool output_to_file = 0;
#define filename ""
#define in_extension "inp"
#define out_extension "out"

// data preprocessing: (e.g.: divisor generating, prime sieve)
void preprocess()
{
    
}

// global variables:
int n, x, y;
int A[mn];
vector <int> positions[mn];

int missing_number() {
    vector <bool> v(n+2, 0);
    for (int i=1; i<=n; i++) v[A[i]] = 1;
    for (int i=1; i<=n+1; i++) if (!v[i]) return i;
}
// main solution goes here:
void execute(int test_number)
{
    cin>>n>>x>>y;
    for (int i=1; i<=n+1; i++) positions[i].clear();
    for (int i=1; i<=n; i++) cin>>A[i];
    for (int i=1; i<=n; i++) positions[A[i]].push_back(i);

    int MI = missing_number();
    priority_queue <pii> PQ;
    for (int i=1; i<=n+1; i++) if (!positions[i].empty()) {
        PQ.push({(int)positions[i].size(), i});
    }

    if (n==x) {
        cout<<"YES\n";
        for (int i=1; i<=n; i++) cout<<A[i]<<" ";
        cout<<"\n";
        return;
    }

    vector <int> ans(n+1, -1);
    ans[0] = inf;

    for (int i=0; i<x; i++) {
        pii p = PQ.top();
        PQ.pop();

        int ind = positions[p.YY].back();
        ans[ind] = p.YY;

        positions[p.YY].pop_back();
        p.XX--;
        if (p.XX>0) PQ.push(p);
    }

    int in_queue = n-x;
    if (PQ.top().XX - (in_queue-PQ.top().XX) > n-y) {
        cout<<"NO\n";
        return;
    }

    int MI_count = n-y;
    int KK = PQ.top().XX - (in_queue-PQ.top().XX);
    // cerr<<test_number<<" "<<KK<<"\n";
    for (int i=0; i<KK; i++, in_queue--, MI_count--) {
        pii p = PQ.top();
        PQ.pop();

        int ind = positions[p.YY].back();
        ans[ind] = MI;

        positions[p.YY].pop_back();
        p.XX--;
        if (p.XX>0) PQ.push(p);
    }

    vector <int> q;


    while (in_queue > 3) {
        in_queue -= 2;
        pii p1 = PQ.top();
        // cerr<<p1.XX<<":"<<p1.YY<<"@"<<PQ.size()<<"\n";
        PQ.pop();
        pii p2 = PQ.top();
        PQ.pop();
        // cerr<<PQ.size() <<"\n";

        int ind1 = positions[p1.YY].back();
        int ind2 = positions[p2.YY].back();
        
        ans[ind1] = p2.YY;
        ans[ind2] = p1.YY;
        q.push_back(ind1);
        q.push_back(ind2);

        positions[p1.YY].pop_back();
        positions[p2.YY].pop_back();
        p1.XX--;
        p2.XX--;
        if (p1.XX>0) PQ.push(p1);
        if (p2.XX>0) PQ.push(p2);
        // cerr<<ind1<<":"<<ind2<<"@"<<PQ.size()<<"\n";
    }

    if (in_queue==1) {
        cout<<"NO\n";
        return;
    } if (in_queue==2) {
        pii p1 = PQ.top();
        PQ.pop();
        pii p2 = PQ.top();
        PQ.pop();

        int ind1 = positions[p1.YY].back();
        int ind2 = positions[p2.YY].back();
        q.push_back(ind1);
        q.push_back(ind2);
        ans[ind1] = p2.YY;
        ans[ind2] = p1.YY;
    } else if (in_queue == 3) {
        pii p1 = PQ.top();
        PQ.pop();
        pii p2 = PQ.top();
        PQ.pop();
        pii p3 = PQ.top();
        PQ.pop();

        int ind1 = positions[p1.YY].back();
        int ind2 = positions[p2.YY].back();
        int ind3 = positions[p3.YY].back();
        q.push_back(ind1);
        q.push_back(ind2);
        q.push_back(ind3);

        ans[ind1] = p2.YY;
        ans[ind2] = p3.YY;
        ans[ind3] = p1.YY;
    }

    for (int i=0; i<MI_count; i++) {
        int ind = q.back();
        ans[ind] = MI;
        q.pop_back();
    }

    cout<<"YES\n";
    for (int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
// REMEMBER TO CHOOSE TEST METHODS
// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Solution by low_



















signed main()
{
#ifdef lowie
    if (!is_interactive)
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
#else
    if (input_from_file) freopen(filename"."in_extension, "r", stdin);
    if (output_to_file) freopen(filename"."out_extension, "w", stdout);
#endif
    if (!is_interactive)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    preprocess();
    int ntest;
    if (is_multitest) cin >> ntest;
    else ntest = 1;

    for (int testno = 1; testno <= ntest; testno++)
    // use for instead of while to serve facebook hacker cup test format
    {
        execute(testno); // only start coding in this function, not in main
    }
}
// Template by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/