#include<bits/stdc++.h>
using namespace std;
string rev(string s){
    string ret=s;
    for(long long int i=0;i<s.size();i++){
        ret[i]=s[s.size()-i-1];
    }
    return ret;
}
void solve(){
    long long int n;cin>>n;
    map<string,long long int>se;
    map<string,long long int>se2;
    map<string,long long int>se3;
    vector<long long int>v;
    long long int t[4]{0};
    string s,rs;
    for(long long int i=0;i<n;i++){
        cin>>s;
        if(s[0]=='0' && s[s.size()-1]=='0'){t[0]++;}
        if(s[0]=='1' && s[s.size()-1]=='1'){t[1]++;}
        if(s[0]=='0' && s[s.size()-1]=='1'){t[2]++;}
        if(s[0]=='1' && s[s.size()-1]=='0'){t[3]++;}
        rs = rev(s); 
        if(s[0]!=s[s.size()-1] && se.find(rs)==se.end()){
            if(s[0]=='0' && s[s.size()-1]=='1'){se2[s]=i+1;}
            if(s[0]=='1' && s[s.size()-1]=='0'){se3[s]=i+1;}
            se[s]=i+1;
        }else if(s[0]!=s[s.size()-1]){
            se.erase(rs);
            if(s[0]=='0' && s[s.size()-1]=='1'){se3.erase(rs);}
            if(s[0]=='1' && s[s.size()-1]=='0'){se2.erase(rs);}
        }
    }
    if(t[0]!=0 && t[1]!=0){
        long long int ans = 0;
        long long int prut = abs(t[3]-t[2]);
        if(t[2]==0 && t[3]==0){
            cout<<-1<<"\n";
            return;
        }
        ans=prut/2;
        long long int margin = 0;
        if(t[2]>t[3]){
            margin=se2.size();
        }else{
            margin=se3.size();
        }
        if(ans>margin){
            cout<<-1<<"\n";
            return;
        }
        cout<<ans<<"\n";
        long long int i=0;
        if(t[2]>t[3]){
            for(pair<string,long long int>p:se2){
                if(i==ans){
                    break;
                }
                cout<<p.second<<" ";
                i++;
                if(i==ans){
                    break;
                }
            }
        }else{
           for(pair<string,long long int>p:se3){
                if(i==ans){
                    break;
                }
                cout<<p.second<<" ";
                i++;
                if(i==ans){
                    break;
                }
            } 
        }
        cout<<"\n";
        //---------------------------------------------------------------------
    }else if(t[0]==0 && t[1]==0){
        long long int prut = abs(t[2]-t[3]);
        long long int ans = prut/2;
        long long int margin = 0;
        if(t[2]>t[3]){
            margin=se2.size();
        }else{
            margin=se3.size();
        }
        if(ans>margin){
            cout<<-1<<"\n";
            return;
        }
        cout<<ans<<"\n";
        long long int i=0;
        if(t[2]>t[3]){
            for(pair<string,long long int>p:se2){
                if(i==ans){
                    break;
                }
                cout<<p.second<<" ";
                i++;
                if(i==ans){
                    break;
                }
            }
        }else{
           for(pair<string,long long int>p:se3){
                if(i==ans){
                    break;
                }
                cout<<p.second<<" ";
                i++;
                if(i==ans){
                    break;
                }
            } 
        }
        cout<<"\n";
        //----------------------------------------------------------------------
    }else if(t[0]==0){
        long long int prut = abs(t[2]-t[3]);
        long long int ans =0;
        if(prut%2==0){
            ans = prut/2;
        }else if(t[2]<t[3]){
            ans = (prut)/2;
        }else{
            ans = prut/2;
        }
        long long int margin = 0;
        if(t[2]>t[3]){
            margin=se2.size();
        }else{
            margin=se3.size();
        }
        if(ans>margin){
            cout<<-1<<"\n";
            return;
        }
        cout<<ans<<"\n";
        long long int i=0;
        if(t[2]>t[3]){
            for(pair<string,long long int>p:se2){
                if(i==ans){
                    break;
                }
                cout<<p.second<<" ";
                i++;
                if(i==ans){
                    break;
                }
            }
        }else{
           for(pair<string,long long int>p:se3){
                if(i==ans){
                    break;
                }
                cout<<p.second<<" ";
                i++;
                if(i==ans){
                    break;
                }
            } 
        }
        cout<<"\n";
    }else if(t[1]==0){
        long long int prut = abs(t[2]-t[3]);
        long long int ans =0;
        if(prut%2==0){
            ans = prut/2;
        }else if(t[2]>t[3]){
            ans = (prut)/2;
        }else{
            ans = prut/2;
        }
        long long int margin = 0;
        if(t[2]>t[3]){
            margin=se2.size();
        }else{
            margin=se3.size();
        }
        if(ans>margin){
            cout<<-1<<"\n";
            return;
        }
        cout<<ans<<"\n";
        long long int i=0;
        if(t[2]>t[3]){
            for(pair<string,long long int>p:se2){
                if(i==ans){
                    break;
                }
                cout<<p.second<<" ";
                i++;
                if(i==ans){
                    break;
                }
            }
        }else{
           for(pair<string,long long int>p:se3){
                if(i==ans){
                    break;
                }
                cout<<p.second<<" ";
                i++;
                if(i==ans){
                    break;
                }
            } 
        }
        cout<<"\n";
    }    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}