#include <bits/stdc++.h>
typedef uint64_t ll;
using namespace std;

struct st{
    ll points, ss, hh;
};
/* inline bool operator <(const st fir, const st oth){ */
/*     ll v1 = fir.ss * oth.hh; */
/*     ll v2 = oth.ss * fir.hh; */
/*     return v1>v2; */
/* } */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<st> arr(n);
    /* st arr[n]; */
    string tmp;
    while(n--){
        ll score = 0, sss = 0, hhh = 0;
        cin >> tmp;
        for(auto const &i: tmp){
            if(i == 's'){
                ++sss;
            }
            else{
                ++hhh;
                score += sss;
            }
        }
        arr[n] = {score,sss,hhh};
    }
    /* sort(arr,arr+n,[](const st &f, const st &s){return f.ss*s.hh > f.hh*s.ss;}); */
    sort(arr.begin(),arr.end(),[](const st &f, const st &s){return f.ss*s.hh > f.hh*s.ss;});
    ll ans = 0, ss = 0;
    for(auto const &i: arr){
        ans += i.points;
        ans += i.hh*ss;
        ss += i.ss;
    }
    cout << ans << '\n';
}