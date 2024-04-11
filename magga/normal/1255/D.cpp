#include<bits/stdc++.h>
using namespace std;
char arro[62];
void process(){
    for(long long int i=0;i<26;i++){
        arro[i]=char(int('a')+i);
    }
    for(long long int i=0;i<26;i++){
        arro[i+26]=char(int('A')+i);
    }
    for(long long int i=0;i<10;i++){
        arro[i+52]=char(int('0')+i);
    }
}
void solve(){
    long long int n,m,chick;cin>>n>>m>>chick;
    long long int arr[n][m];
    char ans[n][m];
    char c;
    long long int count =0;
    for(long long int i=0;i<n;i++){
       for(long long int j=0;j<m;j++){
           cin>>c;
           ans[i][j]='-';
           if(c=='.'){
               arr[i][j]=0;
           }else{
               count++;
               arr[i][j]=1;
           }
        } 
    }
    long long int poo = count/chick;
    long long int doo = count%chick;
    long long int target;
    long long int i1,j1;
    bool flag = true;
    long long int cchar = -1;
    i1 = 0;
    j1 = 0;
    while(chick!=0){
        cchar++;
        target = poo;
        if(doo>0){
            target++;
            doo--;
        }
        while(target!=0){
            ans[i1][j1]=arro[cchar];
            if(arr[i1][j1]==1){
                target--;
            } 
            if(flag){j1++;if(j1==m){flag=false;i1++;j1--;}}
            else{j1--;if(j1==-1){flag=true;i1++;j1++;}}
        }
        chick--;
    }
    char lastchar=arro[cchar];
    for(long long int i=0;i<n;i++){
       for(long long int j=0;j<m;j++){
           if(ans[i][j]=='-'){
             cout<<lastchar;
           }
           else{
             cout<<ans[i][j];
             //lastchar=ans[i][j];
           }
        } 
        cout<<"\n";
    }
    
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    process();
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}