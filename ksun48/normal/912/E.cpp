#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k;
LL p[20];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    cin >> k;

    LL n1 = max(n/2-2, 0LL);

    LL s = 0;
    LL e = 1100000000000000000LL;


    map<LL,LL> cnt;
    cnt[1] = 1;
    for(int j = 0; j < n1; j++){
        map<LL,LL> newcnt2;
        for(map<LL,LL>::iterator it = cnt.begin(); it != cnt.end(); it++){
            LL f = it->first;
            newcnt2[f] += it->second;
            while(f <= e/p[j]){
                f *= p[j];
                newcnt2[f] += it->second;
            }
        }
        cnt = newcnt2;
    }
    map<LL,LL> cnt2;
    cnt2[1] = 1;
    for(int j = n1; j < n; j++){
        map<LL,LL> newcnt2;
        for(map<LL,LL>::iterator it = cnt2.begin(); it != cnt2.end(); it++){
            LL f = it->first;
            newcnt2[f] += it->second;
            while(f <= e/p[j]){
                f *= p[j];
                newcnt2[f] += it->second;
            }
        }
        cnt2 = newcnt2;
    }

    // find number of
    vector<pair<LL,LL> > p1;
    vector<pair<LL,LL> > p2;
    for(map<LL,LL>::iterator it = cnt.begin(); it != cnt.end(); it++){
        p1.push_back({it->first, it->second});
    }
    for(map<LL,LL>::iterator it = cnt2.begin(); it != cnt2.end(); it++){
        p2.push_back({it->first, it->second});
    }
    reverse(p1.begin(), p1.end());

    while(s + 1 < e){
        LL m = (s+e)/2;
        LL total = 0;
        LL sum = 0;
        LL b = 0;
        for(LL a = 0; a < p1.size(); a++){
            while(b < p2.size() && p1[a].first <= m / p2[b].first){
                sum += p2[b].second;
                b++;
            }
            total += sum * p1[a].second;
        }

        if(total >= k){
            e = m;
        } else {
            s = m;
        }
    }
    cout << e << endl;
}