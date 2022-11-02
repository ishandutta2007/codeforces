#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[511][1011];

int dp2[511][1011];

struct box{
    int in,out,w,s,v;
    bool operator<(const box&b2) const{
        if (in==b2.in) return out>b2.out;
        return in<b2.in;
    }
};

vector<box> boxs;

int n, s;

int get(int i, int tw){
    if (dp[i][tw]>-1) return dp[i][tw];
    if (tw<boxs[i].w) {
        dp[i][tw]=0;
        return 0;
    }
    int otw=tw;
    tw-=boxs[i].w;
    tw=min(tw, boxs[i].s);
    for (int ii=0;ii<=1002;ii++){
        dp2[i][ii]=0;
    }
    int iii=0;
    int mv=0;
    for (int ii=i+1;ii<boxs.size();ii++){
        while (iii<boxs[ii].in){
            dp2[i][iii+1]=max(dp2[i][iii+1], dp2[i][iii]);
            iii++;
        }
        if (boxs[ii].in>=boxs[i].in&&boxs[ii].in<boxs[i].out&&boxs[ii].out<=boxs[i].out){
            dp2[i][boxs[ii].out]=max(dp2[i][boxs[ii].in]+get(ii, tw), dp2[i][boxs[ii].out]);
            //cout<<i<<" lol "<<boxs[ii].out<<endl;
            mv=max(mv, dp2[i][boxs[ii].out]);
        }
    }
    dp[i][otw]=boxs[i].v+mv;
    return dp[i][otw];
}

int main(){
    cin>>n>>s;
    for (int i=0;i<n;i++){
        box b;
        cin>>b.in>>b.out>>b.w>>b.s>>b.v;
        b.in++;
        b.out++;
        boxs.push_back(b);
    }
    box b;
    b.in=-1;
    b.out=1001;
    b.w=0;
    b.s=s;
    b.v=0;
    boxs.push_back(b);
    int v=0;
    for (int i=0;i<=502;i++){
        for (int ii=0;ii<=1002;ii++){
            dp[i][ii]=-1;
        }
    }
    sort(boxs.begin(), boxs.end());
    cout<<get(0, s)<<endl;
}