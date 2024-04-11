#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define len(v) (v).size()
#define INF 1000000005
using namespace std;
#define int long long 
typedef pair<int,int>P;

signed main(){
    int n,m;
    cin >> n >> m;
    vector<bool> flag(n); 
    vector<int> a(n);
    map<int,pair<int,int> > mp;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--;
        flag[x] = 1;
        mp[x] = MP(y,i+1);
    }
    rep(i,n) cin>> a[i];
    int leftmost=100;
    int rightmost;
    rep(i,n){
        if(flag[i]){
            leftmost = i;
            break;
        }
    }
    rep(i,n){
        if(flag[n-1-i]){
            rightmost = n-1-i;
            break;
        }
    }
    if(m==1){
        cout << leftmost+1 << endl;
        cout << 1 << endl;
        return 0;
    }
    int tar = -1;
    int ans = -1;
    vector<int> ans_num;
    for(int i=leftmost;i<n;i++){
        bool dead = 0;
        int hero = 0;
        deque<int> dq1,dq2;
        for(int j=leftmost;j<=i;j++){
            if(flag[j]){
                if(hero<mp[j].first){
                    dq1.push_front(j);
                    hero = mp[j].first;
                }else{
                    dq1.push_back(j);
                }
            }else{
                hero += a[j];
            }
            if(hero<0){
                dead = true;
                break;
            }
            //cerr << j << " " << hero << endl;
        }
        if(dead){
            continue;
        }
        hero = 0;
        for(int j=rightmost;j>i;j--){
            if(flag[j]){
                if(hero<mp[j].first){
                    dq2.push_front(j);
                    hero = mp[j].first;
                }else{
                    dq2.push_back(j);
                }
            }else{
                hero += a[j];
            }
            if(hero<0){
                dead = true;
                break;
            }
            //cerr << j << " " << hero << endl;
        }   
        if(dead){
            continue;
        }else{
            ans = i+1;
            for(int z=0;z<dq1.size();z++){
                ans_num.push_back(mp[dq1[z]].second);
            }
            for(int z=0;z<dq2.size();z++){
                ans_num.push_back(mp[dq2[z]].second);
            }
            break;
        }
    }
    if(ans==-1){
        cout << ans << endl;
    }else{
        cout << ans << endl;
        for(int i=0;i<ans_num.size();i++){
            cout << ans_num[i];
            if(i!=ans_num.size()-1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}