#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int T; cin>>T;
    while(T--) {
        int n,m; cin>>n>>m;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        int l[n], r[n];
        int val[n][m];
        for(int i=0;i<n;i++) {
            int mini = 1e9, maxi = -1e9;
            for(int j=0;j<m;j++) {
                val[i][j] = 0;
                if(s[i][j] == 'B')
                    mini = min(mini,j), maxi = max(maxi,j);
            }
            l[i] = mini;
            r[i] = maxi;
//            cout<<i<<' '<<l[i]<<' '<<r[i]<<endl;
        }
        //Now iterate through column
        int mini = 1e9;
        pii ans;
        for(int j=0;j<m;j++) {
            priority_queue<int> pq;
//            cout<<j<<endl;
            //Run up to down
            for(int i=0;i<n;i++) {
//                cout<<"VIS "<<i<<' '<<j<<endl;
                if(l[i] <= j) {
                    pq.push(j-l[i]-i);
                }
                if(r[i] > j) {
                    pq.push(r[i]-j-i);
                }
                if(pq.empty()) continue;
                val[i][j] = max(val[i][j],pq.top()+i);
//                cout<<"CH1 "<<i+1<<' '<<j+1<<' '<<val[i][j]<<endl;
            }
            //Run down to up
            while(!pq.empty()) pq.pop();
            for(int i=n-1;i>=0;i--) {
                if(l[i] <= j) {
                    pq.push(j-l[i]+i);
                }
                if(r[i] > j) {
                    pq.push(r[i]-j+i);
                }
                if(pq.empty()) continue;
                val[i][j] = max(val[i][j],pq.top()-i);
//                cout<<"CH "<<i+1<<' '<<j+1<<' '<<val[i][j]<<endl;
            }

        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(val[i][j] < mini) {
                    mini = val[i][j];
                    ans = {i,j};
                }
            }
        }
        cout<<ans.first+1<<' '<<ans.second+1<<endl;
    }
    return 0;
}