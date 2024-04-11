#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k, ans = 0, ss;
    cin>>n>>k;
    int i,l;
    if(n%2 == 1 && k%2 == 0) {
        cout<<"-1\n"; fflush(stdout);
        return 0;
    }
    for(l=1;l<500;l+=2) {
        //Find min turn
        bool pass = false;
        for(i=0;i<n;i++) {
            if((l*n+2*i)%k == 0 && (((l*n+2*i)/k >= l && i == 0) || ((l*n+2*i)/k >= l+2 && i != 0))) {
                pass = true;
                break;
            }
        }
        if(pass)
            break;
    }
    int a = i;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++) {
        if(i < a)
            pq.push({l+2,i});
        else
            pq.push({l,i});
    }
    int turn = (l*n+2*a)/k;
    while(turn--) {
        cout<<"? ";
        vector<pair<int,int>> save;
        for(int j=0;j<k;j++) {
            pair<int,int> pi = pq.top();
            pq.pop();
            cout<<pi.second+1<<' ';
            if(pi.first != 1)
                save.push_back({pi.first-1,pi.second});
        }
        cout<<"\n"; fflush(stdout);
        cin>>ss;
        ans = ans ^ ss;
        for(auto it: save)
            pq.push(it);
    }
    cout<<"! "<<ans<<"\n"; fflush(stdout);
    return 0;
}