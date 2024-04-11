#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,wanted,inp[nmax];

long long/*cost*/ eval(int i,int cur)
{
    long long s=((-inp[i])%cur+cur)%cur;
    long long t=cur-s;

    long long d=(inp[i]+s)/cur;

    //assert((d-1)*s+d*t==inp[i]);

    //cout<<"eval "<<i<<" "<<cur<<" -> "<<d<<" "<<1LL*s*(d-1)*(d-1)+1LL*t*d*d<<endl;

    return 1LL*s*(d-1)*(d-1)+1LL*t*d*d;
}

priority_queue< pair<long long/*gain*/,int/*id*/> > pq;

int groups[nmax];

int main()
{
    scanf("%i%i",&n,&wanted);

    wanted=wanted-n;

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long outp=0;

    for(int i=1;i<=n;i++)
    {
        outp+=1LL*inp[i]*inp[i];

        groups[i]++;

        pq.push({eval(i,1)-eval(i,2),i});
    }

    while(wanted)
    {
        pair<long long/*gain*/,int/*id*/> tp=pq.top();
        pq.pop();

        //cout<<"found "<<tp.first<<" "<<tp.second<<endl;

        outp=outp-tp.first;

        groups[tp.second]++;

        int i=tp.second;

        pq.push({eval(i,groups[i])-eval(i,groups[i]+1),i});

        wanted--;
    }

    printf("%lld\n",outp);
    return 0;
}