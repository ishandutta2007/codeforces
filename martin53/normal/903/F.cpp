#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42;
int dp[nmax][2<<12];
char inp[4][nmax];
int c[5];
int n;
int get_state(int ind)
{
    return (inp[0][ind]=='*')+(inp[1][ind]=='*')*2+(inp[2][ind]=='*')*4+(inp[3][ind]=='*')*8;
}
int state_3_1=(1<<12)-1-(1<<3)-(1<<7)-(1<<11);
int state_3_2=(1<<12)-1-(1<<0)-(1<<4)-(1<<8);

int state_2_1=(1<<0)+(1<<1)+(1<<4)+(1<<5);
int state_2_2=(1<<4)+(1<<5)+(1<<8)+(1<<9);

int state_2_3=(1<<1)+(1<<2)+(1<<5)+(1<<6);
int state_2_4=(1<<5)+(1<<6)+(1<<9)+(1<<10);

int state_2_5=(1<<2)+(1<<3)+(1<<6)+(1<<7);
int state_2_6=(1<<6)+(1<<7)+(1<<10)+(1<<11);

int rec(int pos,int state)
{
    if(pos>n)return 0;
    if(dp[pos][state]!=-1)return dp[pos][state];
    if(state%16==0)
    {
        dp[pos][state]=rec(pos+1,state/16+get_state(pos+3)*16*16);
        return dp[pos][state];
    }
    //move 4
    int ret=c[4]+rec(pos+4,get_state(pos+4)+get_state(pos+5)*16+get_state(pos+6)*16*16);

    //move 3
    if((state&state_3_1))ret=min(ret,c[3]+rec(pos,(state|state_3_1)^state_3_1));
    if((state&state_3_2))ret=min(ret,c[3]+rec(pos,(state|state_3_2)^state_3_2));
    //move 2
    if((state&state_2_1))ret=min(ret,c[2]+rec(pos,(state|state_2_1)^state_2_1));
    if((state&state_2_2))ret=min(ret,c[2]+rec(pos,(state|state_2_2)^state_2_2));
    if((state&state_2_3))ret=min(ret,c[2]+rec(pos,(state|state_2_3)^state_2_3));
    if((state&state_2_4))ret=min(ret,c[2]+rec(pos,(state|state_2_4)^state_2_4));
    if((state&state_2_5))ret=min(ret,c[2]+rec(pos,(state|state_2_5)^state_2_5));
    if((state&state_2_6))ret=min(ret,c[2]+rec(pos,(state|state_2_6)^state_2_6));

    //move 1
    for(int i=0;i<12;i++)
        if((state&(1<<i)))
            {
            ret=min(ret,c[1]+rec(pos,state^(1<<i)));
            }
    dp[pos][state]=ret;
    //cout<<pos<<" "<<state<<" -> "<<ret<<" "<<__builtin_popcount(state)<<endl;
    return ret;
}
int main()
{
memset(dp,-1,sizeof(dp));
cin>>n;
for(int i=1;i<=4;i++)cin>>c[i];
for(int i=0;i<4;i++)
    for(int j=1;j<=n;j++)cin>>inp[i][j];
cout<<rec(1,get_state(1)+get_state(2)*16+get_state(3)*16*16)<<endl;
return 0;
}