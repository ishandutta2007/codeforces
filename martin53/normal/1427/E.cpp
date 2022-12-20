#include<bits/stdc++.h>
using namespace std;

const int inf=1e6;

const long long MX=0.5*1e18;

vector< pair<char, pair<long long,long long> > > outp,cur_outp,to_add;

mt19937 rng(42);

long long arr[inf];

int pointer=0;

int go(int x)
{
    cur_outp={};
    to_add={};

            pointer=0;

            set<long long> on={};

            int t=1;

            while((1<<t)*2<x)t++;

            long long cur=x;

            for(int j=0;j<=t;j++)
            {
                arr[pointer]=cur;
                pointer++;

                on.insert(cur);

                cur_outp.push_back({'+',{cur,cur}});

                cur=cur*2;
            }


            while(arr[pointer-1]>=x||arr[pointer-1]%2==0)
            {

                long long cur;

                int p=rng()%pointer;
                int q=rng()%pointer;

                if(rng()%2)
                {
                    cur=arr[p]+arr[q];
                    cur_outp.push_back({'+',{arr[p],arr[q]}});
                }
                else
                {
                    cur=arr[p]^arr[q];
                    cur_outp.push_back({'^',{arr[p],arr[q]}});
                }

                if(cur>MX||cur==0)continue;

                if(on.count(cur))continue;
            /*
                if(arr[p]+arr[q]==cur)cout<<arr[p]<<" + "<<arr[q]<<" = "<<cur<<endl;
                else cout<<arr[p]<<" ^ "<<arr[q]<<" = "<<cur<<endl;
            */
                arr[pointer]=cur;
                pointer++;

                on.insert(cur);

                if(cur%2==1&&x>cur)break;

                if((pointer&(pointer-1))==0)
                {
                sort(arr,arr+pointer);

                //cout<<pointer<<endl;

                for(int i=0;i<pointer;i++)
                    for(int j=i+1;j<pointer&&arr[j]-arr[i]<x;j++)
                    {
                        cur=arr[j]^arr[i];

                        if(cur%2==1&&x>cur)
                        {
                            //cout<<arr[j]<<" ^ "<<arr.back()<<endl;
                            arr[pointer]=cur;
                            pointer++;

                            cur_outp.push_back({'^',{arr[j],arr[i]}});

                            break;
                        }
                    }

                }
            }

    set<long long> must={arr[pointer-1]};

    reverse(cur_outp.begin(),cur_outp.end());

    for(auto w:cur_outp)
    {
        long long val=(w.first=='+'?w.second.first+w.second.second:w.second.first^w.second.second);

        //cout<<w.first<<" "<<w.second.first<<" "<<w.second.second<<endl;

        if(must.count(val))
        {
            to_add.push_back(w);

            must.insert(w.second.first);
            must.insert(w.second.second);
        }
    }

    reverse(to_add.begin(),to_add.end());
    for(auto k:to_add)
        outp.push_back(k);

    return arr[pointer-1];
}

void solve(int x)
{
    //cout<<x<<" -> ";

    outp={};

    while(x!=1)x=go(x);

    //cout<<outp.size()<<endl;

    assert(outp.size()<1e5);
}
int main()
{
    /*
    for(int x=1e6-1;x>=3;x=x-2)
    {
        solve(x);
    }


    for(int t=1;t<20;t++)
        solve((1<<t)+1);
    return 0;
    */


    int x;
    scanf("%i",&x);

    solve(x);

    //outp.push_back({'+',{1,0}});

    printf("%i\n",outp.size());

    assert(outp.size()<1e5);

    for(auto k:outp)
    {
        printf("%lld %c %lld\n",k.second.first,k.first,k.second.second);
    }

    return 0;
}