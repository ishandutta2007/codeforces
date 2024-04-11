#include<bits/stdc++.h>
using namespace std;

const int nmax=51;

int n;
int inp[nmax];

int best_score=1e9;
int outp[2][nmax];

//[0] is increasing
//[1] is decreasing

bitset<25*50000+42> on[26][26],idle;

int mem_00,mem_1n,extra;

int cur_table[2][nmax];

void rec(int pos,int upper,int lower,int score_0,int score_1)
{
    //cout<<mem_00<<" "<<mem_1n<<" pos= "<<pos<<" "<<upper<<" "<<lower<<" "<<score_0<<" "<<score_1<<endl;

    if(best_score<=score_0+extra||best_score<=score_1+extra)return;

    if(pos==2*n+1)
    {
        best_score=max(score_0,score_1)+extra;

        for(int i=0;i<2;i++)
            for(int j=1;j<=n;j++)
                outp[i][j]=cur_table[i][j];
        /*
        cout<<best_score<<endl;
        for(int i=0;i<2;i++)
        {
            for(int j=1;j<=n;j++)cout<<cur_table[i][j]<<" ";
            cout<<endl;
        }
        cout<<"---"<<endl;
        */
        return;
    }

    if(on[lower][upper][score_0])return;

    on[lower][upper][score_0]=1;

    if(upper!=n)
    {
        cur_table[0][upper+1]=inp[pos];
        rec(pos+1,upper+1,lower,score_0+inp[pos],score_1);
    }

    if(lower!=1)
    {
        cur_table[1][lower-1]=inp[pos];
        rec(pos+1,upper,lower-1,score_0,score_1+inp[pos]);
    }
}
void solve(int main_1n)
{
    int main_00=1;

    //cout<<main_00<<" "<<main_1n<<" "<<best_score<<endl;

    mem_00=main_00;
    mem_1n=main_1n;

    extra=inp[mem_00]+inp[mem_1n];

    cur_table[0][1]=inp[mem_00];

    int sum=0;
    for(int i=2;i<main_1n;i++)
    {
        cur_table[0][i]=inp[i];
        sum+=inp[i];
    }

    cur_table[1][n]=inp[mem_1n];

    for(int i=main_1n;i<=n;i++)
        for(int j=1;j<=n;j++)
            on[i][j]=idle;

    rec(main_1n+1,main_1n-1,n,sum,0);
}
int main()
{
    scanf("%i",&n);

    for(int i=1;i<=2*n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+2*n+1);

    for(int i=2;i<=n+1;i++)
        solve(i);

    for(int i=0;i<2;i++)
    {
        for(int j=1;j<=n;j++)printf("%i ",outp[i][j]);
        printf("\n");
    }

    return 0;
}