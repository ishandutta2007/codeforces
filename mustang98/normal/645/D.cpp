#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll n, M;
int looser, winner;

int w[100001], l[100001];//winner, looser

bool win[100001];//     -.
bool los[100001];//     -o;
int kol[100001];//     winner,  
vector <int> v[100001];

void dfs(int a)
{
    if (a==winner)
    {
        kol[a]=1;
        return;
    }
    for (int i=0;i<v[a].size();i++)
    {
        if (kol[v[a][i]]==-1) dfs(v[a][i]);
        kol[a]=max(kol[a], kol[v[a][i]]+1);
    }
}

bool check(int k)
{
    looser=-1;//  (  )
    winner=-1;//  (  )
    for (int i=0;i<n;i++) {v[i].clear(); win[i]=false; los[i]=false;}
    for (int i=0;i<k;i++)
    {
        v[l[i]].push_back(w[i]);
        win[w[i]]=true;
        los[l[i]]=true;
    }

//gfgfgfg
//for (int i=0;i<n;i++) cout<<win[i];
//fgfgfg
    for (int i=0;i<n;i++)
    {
        if (win[i]) continue;
        if (looser == -1) looser = i;
        else return false;// 
    }

    for (int i=0;i<n;i++)
    {
        if (los[i]) continue;
        if (winner == -1) winner = i;
        else return false;// 
    }
    for (int i=0;i<n;i++) kol[i]=-1;
    dfs(looser);
    if (kol[looser]==n) return true;
    return false;
}

int main()
{
    int k, kl=0, kr;//  ,  
    cin>>n>>M;
    kr=M;
    for (int i=0;i<M;i++)
    {
        cin>>w[i]>>l[i];
        w[i]--;
        l[i]--;
    }
    if (check(M)==false)
    {
        cout<<-1;
        return 0;
    }

    while (kl+1<kr)
    {
        k = (kl+kr)/2;
        if (check(k)) kr=k;
        else kl=k;
    }
    cout<<kr;
    return 0;
}