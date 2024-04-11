#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, k, m;

vector<LL> reducebus(vector<LL> bus){
    vector<LL> ans;
    LL last = -1;
    LL cnt = 0;
    for(LL i = 0; i < bus.size(); i++){
        ans.push_back(bus[i]);
        if(bus[i] != last){
            cnt = 0;
            last = bus[i];
        }
        cnt++;
        if(cnt >= k){
            for(LL j = 0; j < k; j++){
                ans.pop_back();
            }
            cnt = 0;
            if(ans.size() > 0){
                last = ans[ans.size()-1];
                for(int j = 0; j < ans.size(); j++){
                    if(ans[ans.size() - 1 - j] == last){
                        cnt++;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    cin >> n >> k >> m;
    vector<LL> bus;
    for(LL i = 0; i < n; i++){
        LL a;
        cin >> a;
        bus.push_back(a);
    }
    bus = reducebus(bus);
    LL s = 0;
    LL e = (LL)bus.size() -1;
    while(1){
        if(s > e) break;
        if(e - s + 1 <= k){
            break;
        }
        if(bus[s] != bus[e]) break;
        LL s1 = s;
        LL e1 = e;
        LL v = bus[s];
        while(s1 - s + e - e1 < k){
            if(bus[s1] == v){
                s1++;
            } else if(bus[e1] == v){
                e1--;
            } else {
                break;
            }
        }
        if(s1 - s + e - e1 == k){
            s = s1;
            e = e1;
        } else {
            break;
        }
    }
    LL len = e - s + 1;
    LL allsame = 1;
    for(LL i = s; i + 1 <= e; i++){
        if(bus[i] != bus[i+1]) allsame = 0;
    }
    if(allsame){
        LL nummid = (m)*len;
        nummid %= k;
        vector<LL> newbus;
        for(LL i = 0; i < s; i++){
            newbus.push_back(bus[i]);
        }
        for(LL i = 0; i < nummid; i++){
            newbus.push_back(bus[s]);
        }
        for(LL i = e+1; i < bus.size(); i++){
            newbus.push_back(bus[i]);
        }
        newbus = reducebus(newbus);
        cout << newbus.size() << endl;
        return 0;
    }
    vector<LL> newbus;
    for(LL i = 0; i < s; i++){
        newbus.push_back(bus[i]);
    }

    LL numleft = m;
    while(numleft && newbus.size() <= (3*n + 1000)){
        numleft--;
        for(LL i = s; i <= e; i++){
            newbus.push_back(bus[i]);
        }
    }

    for(LL i = e+1; i < bus.size(); i++){
        newbus.push_back(bus[i]);
    }

    newbus = reducebus(newbus);

    cout << (newbus.size() + numleft * len) << endl;
}