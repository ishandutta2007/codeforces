#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42;
int n,k;
string inp[nmax];

int can[nmax][nmax];

bool in[10][7];

int dist(int num,int pos)
{
    int ret=0;
    for(int i=0;i<7;i++)
        if(inp[pos][i]-'0'!=in[num][i])
        {
            if(in[num][i]==0)return k+1;
            ret++;
        }
    return ret;
}
void prec()
{
    in[0][0]=1;in[0][1]=1;in[0][2]=1;in[0][3]=0;in[0][4]=1;in[0][5]=1;in[0][6]=1;

    in[1][0]=0;in[1][1]=0;in[1][2]=1;in[1][3]=0;in[1][4]=0;in[1][5]=1;in[1][6]=0;

    in[2][0]=1;in[2][1]=0;in[2][2]=1;in[2][3]=1;in[2][4]=1;in[2][5]=0;in[2][6]=1;

    in[3][0]=1;in[3][1]=0;in[3][2]=1;in[3][3]=1;in[3][4]=0;in[3][5]=1;in[3][6]=1;

    in[4][0]=0;in[4][1]=1;in[4][2]=1;in[4][3]=1;in[4][4]=0;in[4][5]=1;in[4][6]=0;

    in[5][0]=1;in[5][1]=1;in[5][2]=0;in[5][3]=1;in[5][4]=0;in[5][5]=1;in[5][6]=1;

    in[6][0]=1;in[6][1]=1;in[6][2]=0;in[6][3]=1;in[6][4]=1;in[6][5]=1;in[6][6]=1;

    in[7][0]=1;in[7][1]=0;in[7][2]=1;in[7][3]=0;in[7][4]=0;in[7][5]=1;in[7][6]=0;

    in[8][0]=1;in[8][1]=1;in[8][2]=1;in[8][3]=1;in[8][4]=1;in[8][5]=1;in[8][6]=1;

    in[9][0]=1;in[9][1]=1;in[9][2]=1;in[9][3]=1;in[9][4]=0;in[9][5]=1;in[9][6]=1;
}

int can_fill(int pos,int digits)
{
    if(digits<0)return 0;

    if(pos>n)return digits==0;

    if(can[pos][digits]!=-1)return can[pos][digits];

    for(int i=0;i<=9;i++)
        if(can_fill(pos+1,digits-dist(i,pos)))
        {
            //cout<<pos<<" "<<digits<<" -> 1"<<endl;
            can[pos][digits]=1;
            return 1;
        }

    //cout<<pos<<" "<<digits<<" -> 0"<<endl;

    can[pos][digits]=0;
    return 0;
}
int main()
{
    prec();

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];
    }

    memset(can,-1,sizeof(can));

    if(can_fill(1,k)==0)
    {
        cout<<-1<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=9;j>=0;j--)
        {
            if(can_fill(i+1,k-dist(j,i)))
            {
                cout<<j;
                k=k-dist(j,i);
                break;
            }
        }
    }
    cout<<endl;
    return 0;
}