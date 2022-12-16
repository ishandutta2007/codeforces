#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;

int seen[6];

int possible[nmax];

int there[nmax];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string inp;
    cin>>inp;
    for(auto k:inp)
        seen[k-'a']++;

    for(int i=1;i<=inp.size();i++)
        possible[i]=(1<<6)-1;

    int m;
    int pos;
    string current;

    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>pos>>current;

        possible[pos]=0;
        for(auto k:current)
            possible[pos]+=(1<<(k-'a'));
    }

    for(int i=1;i<=inp.size();i++)
        there[possible[i]]++;

    for(pos=1;pos<=inp.size();pos++)
    {
        //cout<<"pos= "<<pos<<" ";for(int j=0;j<6;j++)cout<<seen[j]<<" ";cout<<endl;

        int actual=0;
        while(actual<6)
        {
            if((possible[pos]&(1<<actual))==0||seen[actual]==0)
            {
                actual++;
                continue;
            }
            //test with hall's theorem

            seen[actual]--;
            there[possible[pos]]--;

            bool ok=1;
            for(int left_side=0;left_side<(1<<6);left_side++)
            {
                int want=0,available=0;
                for(int j=0;j<6;j++)
                    if((left_side&(1<<j)))want=want+seen[j];

                for(int right_side=0;right_side<(1<<6);right_side++)
                {
                    if((left_side&right_side))available+=there[right_side];
                }

                if(want>available)
                {
                    ok=0;
                    break;
                }
            }

            if(ok==0)
            {
                seen[actual]++;
                there[possible[pos]]++;
                actual++;
                continue;
            }

            cout<<char('a'+actual);
            break;
        }

        if(actual==6)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    return 0;
}