#include<bits/stdc++.h>
using namespace std;

inline bool valid(int y,int x){
    if(y==3&&x==1)return true;
    return y>=0&&y<3&&x>=0&&x<3;
}

int X[]={1,0,1,2,0,1,2,0,1,2};
int Y[]={3,0,0,0,1,1,1,2,2,2};

int main(){
    int n;cin>>n;
    string s;cin>>s;

    int cnt=0;
    for(int i=0;i<10;i++){
        int y=Y[i],x=X[i];
        bool ok=true;
        for(int j=0;j<n-1;j++){
            y+=Y[s[j+1]-'0']-Y[s[j]-'0'];
            x+=X[s[j+1]-'0']-X[s[j]-'0'];
            if(!valid(y,x)){
                ok=false;
                break;
            }
        }
        if(ok)cnt++;
    }

    if(cnt==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}