#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

set<long long> fact;
map<long long, vector<long long> > same;
long long N;

int main()
{
    scanf ("%lld",&N);
    for (long long i=1;i*i<=N;i++) if (N % i == 0){
        fact.insert(i);
        fact.insert(N/i);
    }

    for (auto p : fact) if (p > 2){
        p--; bool good = 1; long long t = p, d = p;
        for (long long i=2;i*i<=p;i++) if (p % i == 0){
            while (p % i == 0) p /= i;
            d = i;
            if (p > 1){
                good = 0;
                break;
            }
        }
        if (good) same[d].push_back(t+1);
    }

    vector<pair<long long, long long> > prv;
    prv.push_back(make_pair(1,1));
    for (auto p : same){
        vector<pair<long long, long long> > nxt = prv;
        for (auto u : prv){
            for (auto v : p.second){
                if (N / u.first % v == 0) nxt.push_back(make_pair(u.first*v,u.second));
            }
        }
        sort(nxt.begin(),nxt.end());
        prv.clear();
        prv.push_back(nxt[0]);
        for (int i=1;i<nxt.size();i++){
            if (prv.back().first == nxt[i].first) prv.back().second += nxt[i].second;
            else prv.push_back(nxt[i]);
        }
    }

    long long ans = 0;
    if (prv.back().first == N) ans = prv.back().second;
    printf ("%lld\n",ans);

    return 0;
}