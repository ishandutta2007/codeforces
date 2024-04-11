#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,m,k;cin>>n>>m>>k;
    if(k>4*n*m-2*n-2*m){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    vector<string>v;
    long long int command = 0;
    if(m==1){
        if(k<=n-1){
            cout<<1<<"\n";
            cout<<k<<" D"<<"\n";
        }else if(k<=2*n-2){
            cout<<2<<"\n";
            cout<<n-1<<" D"<<"\n";
            cout<<k+1-n<<" U"<<"\n";
        }
        return;    
    }
    if(k<=m-1){
        cout<<1<<"\n";
        cout<<k<<" R"<<"\n";
        return;
    }else if(k<=2*m-2){
        cout<<2<<"\n";
        cout<<m-1<<" R"<<"\n";
        cout<<k+1-m<<" L"<<"\n";
        return;
    }
    string s = to_string(m-1)+" R";
    v.push_back(s);
    s = to_string(m-1)+" L";
    v.push_back(s);
    s = to_string(1)+" D";
    v.push_back(s);
    k-=2*m-1;
    long long int p = 2; 
    while(k!=0 && p<=n){
        p++;
        if(k<=3*(m-1)){
            if(k>=3){
                s = to_string(k/3)+" RUD";
                v.push_back(s);
            }
            if(k%3==1){
                s = to_string(1)+" R";
                v.push_back(s);
            }else if(k%3==2){
                s = to_string(1)+" RU";
                v.push_back(s);
            }
            k=0;
            break;
        }
        k-=3*(m-1);
        s = to_string(m-1)+" RUD";
        v.push_back(s);
        if(k<=m-1){
            s = to_string(k)+" L";
            v.push_back(s);
            k=0;
            break;
        }
        s = to_string(m-1)+" L";
        v.push_back(s);
        if(p!=n+1){
            s = to_string(1)+" D";
            v.push_back(s);
            k--;
        }
        k-=m-1;
    }
    if(p==n+1 && k!=0){
        s = to_string(k)+" U";
        v.push_back(s);
    }
    cout<<v.size()<<"\n";
    for(string s:v){
        cout<<s<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}