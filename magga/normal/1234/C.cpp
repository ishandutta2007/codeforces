#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    string u,l;
    cin>>u>>l;
    bool b = true;
    for(long long int i = 0 ;i < n ; i++){
        if(b){
            if(u[i]=='1' || u[i]=='2'){
                continue;
            }else if (l[i]!='1' && l[i]!='2'){
                b = false;
            }else{
                cout << "NO" <<endl;
                return;
            }
        }else{
            if(l[i]=='1' || l[i]=='2'){
                continue;
            }else if (u[i]!='1' && u[i]!='2'){
                b = true;
            }else{
                cout << "NO" <<endl;
                return;
            }
        }
    }
    if(!b){
        cout<<"YES"<<endl;
        return;
    }
    cout << "NO" <<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}