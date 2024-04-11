//
// Created by Nitit Jongsawatsataporn on 3/6/2022 AD.
//
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    while(T--) {
        int n,m; cin>>n>>m;
        int a[n],b[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        ll s1 = 0, s2 = 0;
        vector<int> cut;
        cut.push_back(0);
        for(int i=0;i<n;i++) {
            s1 += a[i];
            s2 += b[i];
            if(s1 == s2) {
                cut.push_back(i+1);
            }
        }
 
        vector<pii> interval;
        set<int> left;
        for(int i=0;i<cut.size();i++){
            left.insert(i); //Store all not-optimize interval
        }
        vector<int> re[cut.size()]; //Store requirment of this interval
        int siz[m]; //Store the size needed for query
 
        // cout<<"CUT\n";
        // for(auto it: cut)
        //     cout<<it<<' ';
        // cout<<'\n';
 
        for(int i=0;i<m;i++) {
            //B-search for l r
            int l,r,la,ra; cin>>l>>r;
            int mi = 0, ma = cut.size()-1;
            //Search for first one that is go not before l
            while(mi < ma) {
                int md = mi + ma >> 1;
                if(md == mi) {
                    if(cut[mi] < l)
                        mi = ma;
                    else
                        ma = mi;
                }
                else {
                    if(cut[md] >= l)
                        ma = md;
                    else
                        mi = md;
                }
            }
            vector<int> req;
            if(cut[mi-1] != l-1) {
                req.push_back(mi);
                // cout<<i<<" L "<<mi<<endl;
            }
            la = mi; //From this point, we get for free
            mi = 0, ma = cut.size()-1;
            //Search for first one that is go not after than l,r
            while(mi < ma) {
                int md = mi + ma >> 1;
                // if(i == 0) {
                //     cout<<mi<<' '<<ma<<' '<<cut[mi]<<' '<<cut[ma]<<endl;
                // }
                if(md == mi) {
                    if(cut[mi] < r)
                        mi = ma;
                    else
                        ma = mi;
                }
                else {
                    if(cut[md] >= r)
                        ma = md;
                    else
                        mi = md;
                }
            }
            if(cut[mi] != r) { //Space left
                req.push_back(mi);
                // cout<<i<<" R "<<mi<<' '<<cut[mi]<<' '<<r<<' '<<cut[mi+1]<<endl;
            }
            //What if la > ra? -> Then we will never use it!
            ra = mi;
            interval.push_back({la,ra});
            siz[i] = req.size();
            for(auto it: req) {
                re[it].push_back(i);
            }
            // cout<<i<<' '<<la<<' '<<ra<<' '<<" REQ ";
            // for(auto it: req)
            //     cout<<it<<' ';
            // cout<<endl;
        }
        if(cut.back() != n) { //If sum not equal. it's doom
            cout<<"NO\n";
            continue;
        }
 
        queue<int> qu;
        for(int i=0;i<m;i++) {
            if(siz[i] == 0) {
                qu.push(i); //Interval that can be used for free
            }
        }
        while(!qu.empty()) {
            int nd = qu.front();
            qu.pop();
            // cout<<nd<<endl;
            auto pt = left.lower_bound(interval[nd].first); //First position
            vector<int> del;
            while(pt != left.end()) {
                const int e = *pt;
                // cout<<e<<endl;
                if(e > interval[nd].second) break;
                del.push_back(e);
                for(auto it: re[e]) {
                    siz[it]--;
                    if(siz[it] == 0) {
                        qu.push(it);
                    }
                }
                pt++;
            }
            for(auto it: del)
                left.erase(it);
        }
        if(left.size() == 1) {
            cout<<"YES\n";
        }
        else {
            bool pass = true;
            for(auto it: left) {
                const int e = it;
                if(it == 0) continue;
                pass &= (cut[it]-cut[it-1] == 1);
            }
            if(!pass)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
    return 0;
}