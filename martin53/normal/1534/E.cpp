#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n,k;

int cnt[nmax];

bool cmp(pair<int/*cnt*/,int/*id*/> a,pair<int/*cnt*/,int/*id*/> b)
{
    return a.first>b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>n>>k;

    if(k%2==0&&n%2==1)
    {
        cout<<-1<<endl;
        return 0;
    }

    for(int q=1;true;q++)
        if(k*q%2==n%2)
        {
            int allow=q;
            if(allow%2==0)allow--;

            int low=n,high=allow*n;

            int need=k*q;

            //cout<<"q= "<<q<<" low= "<<low<<" high= "<<high<<" need= "<<need<<endl;

            if(low<=need&&need<=high)
            {
                for(int j=1;j<=n;j++)
                {
                    //cout<<"j= "<<j<<" low= "<<low<<" high= "<<high<<" need= "<<need<<endl;

                    for(int now=1;true;now=now+2)
                    {
                        int low_remain=low-1;
                        int high_remain=high-allow;

                        int remain=need-now;

                        if(low_remain<=remain&&remain<=high_remain)
                        {
                            cnt[j]=now;

                            //cout<<"cnt "<<j<<" = "<<now<<endl;

                            low=low_remain;
                            high=high_remain;

                            need=remain;

                            break;
                        }
                    }
                }

                int outp=0;

                for(int step=1;step<=q;step++)
                {
                    vector< pair<int/*cnt*/,int/*id*/> > there={};

                    for(int i=1;i<=n;i++)there.push_back({cnt[i],i});

                    sort(there.begin(),there.end(),cmp);

                    cout<<"?";

                    for(int j=0;j<k;j++)
                    {
                        cout<<" "<<there[j].second;

                        cnt[there[j].second]--;
                    }

                    cout<<endl;

                    int cur;
                    cin>>cur;

                    outp=outp^cur;
                }

                cout<<"! "<<outp<<endl;
                exit(0);
            }
        }
    return 0;
}