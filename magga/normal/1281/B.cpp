#include<bits/stdc++.h>
using namespace std;
void solve(){
    string a,b;cin>>a>>b;
    bool flag = false;
    for(long long int i=0;i<min(a.size(),b.size());i++){
        if(a[i]<b[i]){
            cout<<a<<"\n";
            return;
        }else if(a[i]==b[i]){
            for(long long int j=i+1;j<a.size();j++){
                if(a[j]<b[i]){
                    char c = a[i];
                    a[i] = a[j];
                    a[j] = c;
                    cout<<a<<"\n";
                    return;
                }
            }
        }else if(a[i]>b[i]){
           for(long long int j=i;j<a.size();j++){
                if(a[j]<b[i]){
                    char c = a[i];
                    a[i] = a[j];
                    a[j] = c;
                    cout<<a<<"\n";
                    return;
                }
            }
            long long int last = i;
            for(long long int j=i;j<a.size();j++){
                if(a[j]==b[i]){
                    last = j;
                }
            }
            char c = a[i];
            a[i] = a[last];
            a[last] = c;
            if(a.compare(b)<0 || (b.size()>a.size() && b.substr(0,a.size())==a)){
                cout<<a<<"\n";
            }else{
                cout<<"---"<<"\n";
            }    
            return;
        }
    }
    if(a.compare(b)<0 || (b.size()>a.size() && b.substr(0,a.size())==a)){
        cout<<a<<"\n";
    }else{
        cout<<"---"<<"\n";
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