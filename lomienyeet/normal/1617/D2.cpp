#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=1e4+5;
int nom(int a,int b,int c){
    cout<<"? "<<a<<" "<<b<<" "<<c<<"\n";
    fflush(stdout);
    int z;
    cin>>z;
    return z;
}
void eat(){
    int n;
    cin>>n;
    int arr[n+1],ee[n+1]={};
    pair<int,int> p={-1,-1};
    for(int i=1;i<=n;i++)arr[i]=-1;
    for(int i=1;i<n-1;i+=3){
        ee[i]=nom(i,i+1,i+2);
        if(p.ff==-1&&i>1&&ee[i]!=ee[i-3]){
            ee[i-2]=nom(i-2,i-1,i);
            ee[i-1]=nom(i-1,i,i+1);
            for(int j=i-2;j<=i;j++){
                if(ee[j]!=ee[j-1]){
                    if(!ee[j-1])p={j-1,j+2};
                    else p={j+2,j-1};
                    ee[p.ff]=1;
                    ee[p.ss]=0;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i+=3){
        if((i<=p.ff&&p.ff<=i+2)||(i<=p.ss&&p.ss<=i+2)){
            for(int j=i;j<=i+2;j++){
                if(j==p.ff||j==p.ss)continue;
                ee[j]=1-nom(p.ff,p.ss,j);
            }
            continue;
        }
        if(!ee[i]){
            pair<int,int> qry={nom(i,i+1,p.ss),nom(i+1,i+2,p.ss)};
            if(qry.ff&&qry.ss){
                ee[i]=ee[i+2]=1;
                ee[i+1]=0;
            }
            else if(qry.ff){
                ee[i+1]=ee[i+2]=1;
                ee[i]=0;
            }
            else if(qry.ss){
                ee[i]=ee[i+1]=1;
                ee[i+2]=0;
            }
            else ee[i]=ee[i+1]=ee[i+2]=1;
        }
        else{
            pair<int,int> qry={nom(i,i+1,p.ff),nom(i+1,i+2,p.ff)};
            if(qry.ff&&qry.ss)ee[i]=ee[i+1]=ee[i+2]=0;
            else if(qry.ff){
                ee[i]=ee[i+1]=0;
                ee[i+2]=1;
            }
            else if(qry.ss){
                ee[i+1]=ee[i+2]=0;
                ee[i]=1;
            }
            else{
                ee[i]=ee[i+2]=0;
                ee[i+1]=1;
            }
        }
    }
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(ee[i])v.push_back(i);
    }
    cout<<"! "<<v.size()<<" ";
    for(auto i:v)cout<<i<<" ";
    fflush(stdout);
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}