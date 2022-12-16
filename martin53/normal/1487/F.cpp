#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,MX=200+5,ADD=MX/10+3;

short dp[51][MX][MX][ADD*2+1];

string n;

int rec(int pos,int plus,int minus,int carry)
{
    if(pos==-1)
    {
        if(carry==0)return 0;
        return 1e9;
    }

    //cout<<pos<<" "<<plus<<" "<<minus<<" "<<carry<<endl;

    //assert(0<=carry+ADD);
    //assert(carry+ADD<ADD*2+1);

    if(dp[pos][plus][minus][carry+ADD]!=-1)return dp[pos][plus][minus][carry+ADD];

    int ret=(1<<15)-1;

    if(plus)ret=min(ret,rec(pos,plus-1,minus,carry));
    if(minus)ret=min(ret,rec(pos,plus,minus-1,carry));

    int plus_new=plus,minus_new=minus;

            int digit=carry+plus_new-minus_new;

            int dig=(digit%10+10)%10;

            int carry_new=(digit-dig)/10;

            if(dig==n[pos]-'0')
            {
                ret=min(ret,rec(pos-1,plus_new,minus_new,carry_new)+plus_new+minus_new);
            }
            //if(pos==5&&rec(pos-1,plus_new,minus_new,carry_new)+plus_new+minus_new==19)cout<<plus_new<<" "<<minus_new<<" "<<rec(pos-1,plus_new,minus_new,carry_new)<<endl;

    dp[pos][plus][minus][carry+ADD]=ret;

    //cout<<pos<<" "<<plus<<" "<<minus<<" "<<carry<<" -> "<<ret<<endl;

    return ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));

    cin>>n;

    n="0"+n;

    cout<<rec(n.size()-1,MX-1,MX-1,0)<<endl;
    return 0;
}