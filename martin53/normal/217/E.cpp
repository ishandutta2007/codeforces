#include<bits/stdc++.h>
#include <ext/rope> //header with rope
using namespace std;
using namespace __gnu_cxx; //namespace with rope and some additional stuff

const int nmax=5e3+42,kmax=3e6+42;

crope output;

int k;
int n;
string input;

pair<int,int> updates[nmax];

void solve(int line,int letters)
{
    //cout<<"solve "<<line<<" "<<letters<<endl;

    if(line<=0)
    {
        output.push_back('-');
        for(int i=0;i<letters;i++)output.push_back(input[i]);
        return;
    }

    int l_=updates[line].second+1,r_=updates[line].second*2-updates[line].first+1;

    int common=min(r_,letters)-max(1,l_)+1;
    common=max(common,0);

    solve(line-1,letters-common);

    if(common==0)return;

    int taken=0;

    char *help=new char[common+1];
    help[common]=0;

    //cout<<line<<" -> "<<common<<endl;

    for(int id_now=updates[line].first+1;id_now<=updates[line].second&&taken<common;id_now=id_now+2)
    {
        help[taken]=output[id_now];
        taken++;
    }

    for(int id_now=updates[line].first;id_now<=updates[line].second&&taken<common;id_now=id_now+2)
    {
        help[taken]=output[id_now];
        taken++;
    }

    //for(int j=0;j<common;j++)cout<<help[j];cout<<endl;

    output.insert(updates[line].second+1,help);

    //cout<<"after line "<<line<<" -> ";for(auto p:output)cout<<p;cout<<endl;
    //cout<<"common: ";cout<<common<<" -> ";for(int i=1;i<=common;i++)cout<<help[i];cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>input;
    cin>>k;
    cin>>n;

    for(int i=1;i<=n;i++)cin>>updates[i].first>>updates[i].second;

    solve(n,k);

    for(int i=1;i<=k;i++)cout<<output[i];cout<<endl;
    return 0;
}