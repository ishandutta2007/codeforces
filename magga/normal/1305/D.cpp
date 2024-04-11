#include<bits/stdc++.h>
    using namespace std;
    void pre(){}
    pair<long long int,long long int>p{0,0};
    bool flag[10001];
    pair<bool,long long int> dfs(long long int i,map<long long int,set<long long int>>&m){
        long long int count = 0;
        flag[i]=1;
        long long int cur =0;
        for(auto i:m[i]){
            if(!flag[i]){
                cur++;
            }
        }
        if(cur==0){
            return {true,i};
        }
        if(cur==1){
            for(auto j:m[i]){
                if(!flag[j]){
                    return dfs(j,m);
                }
            }
        }
        for(auto j:m[i]){
            if(flag[j]){
                continue;
            }
            auto k = dfs(j,m);
            if(k.first==true){
                if(count == 0){
                    p.first=k.second;
                    count++;
                }
                else if(count == 1){
                    p.second=k.second;
                    break;
                }
            }
        }
        return {0,1};
    }
    void solve(){
        long long int n,a,b,d;cin>>n;
        map<long long int,set<long long int>>m;
        for(long long int i=0;i<n-1;i++){
            cin>>a>>b;
            m[a].insert(b);
            m[b].insert(a);
        }
        while(m.size()>1){
            for(auto i:m){
                flag[i.first]=0;
            }
            if(m.size()==2){
                a = (*m.begin()).first;
                auto p = m.begin();
                p++;
                b = (*p).first;
                cout<<"? "<<a<<" "<<b<<"\n";
                cout.flush();
                long long int ans =0;
                cin>>ans;
                cout<<"! "<<ans<<'\n';
                return;
            }
            auto a = dfs((*m.begin()).first,m);
            if(a.first==1){
                cout<<"? "<<(*m.begin()).first<<" "<<a.second<<"\n";
                cout.flush();
                long long int ans =0;
                cin>>ans;
                cout<<"! "<<ans<<'\n';
                return;
            }
            cout<<"? "<<p.first<<" "<<p.second<<"\n";
            cout.flush();
            long long int ans =0;
            cin>>ans;
            if(ans==p.first || m[ans].size()==2 || ans==p.second){
                cout<<"! "<<ans<<"\n";
                return;
            }
            stack<long long int>val;
            stack<long long int>va;
            for(auto i:m){
                flag[i.first]=0;
            }
            val.push(p.first);
            va.push(p.first);
            while(val.size()!=0){
                long long int k = val.top();
                flag[k]=true;
                val.pop();
                va.push(k);
                if(k==p.second){
                    break;
                }
                for(long long int i:m[k]){
                    if(!flag[i]){
                        val.push(i);
                    }
                }
                va.pop();
            }
            while(va.size()!=0){
                long long int k = va.top();
                va.pop();
                if(k!=ans){
                    m.erase(k);
                    m[ans].erase(k);
                }
            }
        }
        cout<<"! "<<(*m.begin()).first<<"\n";
    }
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        pre();
        long long int num = 1;
        //cin>>num;
        for(long long int i=0;i<num;i++){
            solve();
        }   
    }