#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

struct dsu{
    int gr;
    vector<int> p;

    dsu(int n) {
        gr = n;
        for(int i=0;i<n;i++)
            p.push_back(i);
    }

    int find_p(int s) {
//        cout<<s<<' '<<p[s]<<endl;
        if(p[s] == s)
            return s;
        p[s] = find_p(p[s]);
        return p[s];
    }

    void merge(int s, int t) {
        s = find_p(s);
        t = find_p(t);
//        cout<<s<<' '<<t<<endl;
        if(s != t) {
            p[s] = t;
            gr--;
        }
    }
};

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int a[n]; int ans = 0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            if(a[i] == 0) {
                a[i]++;
                ans++;
            }
        }
        //Check 0;
        {
            dsu ds = dsu(n);
            vector<int> v[30];
            for(int i=0;i<n;i++) {
                for(int j=0;j<30;j++) {
                    if(a[i]&(1<<j))
                        v[j].push_back(i);
                }
            }
            for(int i=0;i<30;i++) {
                // if(v[i].size() <= 1) continue;
                for(int j=0;j+1<v[i].size();j++) {
                    ds.merge(v[i][j], v[i][j + 1]);
                }
            }
            if(ds.gr == 1) {
                cout<<ans<<'\n';
                for(int i=0;i<n;i++)
                    cout<<a[i]<<' ';
                cout<<endl;
                continue;
            }
        }
        ans++;
//        cout<<"??\n";
        //Check 1;
        bool pass = false;
        for(int q=0;q<n;q++){
            a[q]++;
            dsu ds = dsu(n);
            vector<int> v[30];
            for(int i=0;i<n;i++) {
                for(int j=0;j<30;j++) {
                    if(a[i]&(1<<j))
                        v[j].push_back(i);
                }
            }
            for(int i=0;i<30;i++) {
                if(v[i].size() <= 1) continue;
                for(int j=0;j<v[i].size()-1;j++)
                    ds.merge(v[i][j],v[i][j+1]);
            }
            if(ds.gr == 1) {
                pass = true;
                cout<<ans<<'\n';
                for(int i=0;i<n;i++)
                    cout<<a[i]<<' ';
                cout<<endl;
                break;
            }
            a[q]--;
        }
        if(pass) continue;
        pass = false;
        for(int q=0;q<n;q++){
            a[q]--;
            dsu ds = dsu(n);
            vector<int> v[30];
            for(int i=0;i<n;i++) {
                for(int j=0;j<30;j++) {
                    if(a[i]&(1<<j))
                        v[j].push_back(i);
                }
            }
            for(int i=0;i<30;i++) {
                if(v[i].size() <= 1) continue;
                for(int j=0;j<v[i].size()-1;j++)
                    ds.merge(v[i][j],v[i][j+1]);
            }
            if(ds.gr == 1) {
                pass = true;
                cout<<ans<<'\n';
                for(int i=0;i<n;i++)
                    cout<<a[i]<<' ';
                cout<<endl;
                break;
            }
            a[q]++;
        }
        if(pass) continue;
        int maxi = 0;
        ans++;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int cur = (a[i] & (-a[i]));
            if(cur == maxi) {
                v.push_back(i);
                continue;
            }
            if(cur > maxi) {
                v.clear();
                maxi = cur;
                v.push_back(i);
            }
        }
        a[v[0]]--;
        a[v[1]]++;
        cout<<ans<<'\n';
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}