#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int main(){
    string S;
    cin>>S;
    S+=",";
    string A="-",B="-";
    int cur=0;
    while(cur<S.size()){
        int next=cur;
        while(next<S.size()&&S[next]!=';'&&S[next]!=',')next++;
        string sub=S.substr(cur,next-cur);
        bool f=true;
        rep(i,sub.size())if(!isdigit(sub[i]))f=false;
        if(sub.size()>1&&sub[0]=='0')f=false;
        if(sub.size()==0)f=false;
        if(f){
            if(A=="-")A=sub;
            else A+=","+sub;
        }
        else{
            if(B=="-")B=sub;
            else B+=","+sub;
        }
        cur=next+1;
    }
    if(A!="-")cout<<'\"'<<A<<'\"'<<endl;
    else cout<<A<<endl;
    if(B!="-")cout<<'\"'<<B<<'\"'<<endl;
    else cout<<B<<endl;
    return 0;
}