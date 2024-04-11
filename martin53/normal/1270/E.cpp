#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n;
pair<int,int> inp[nmax];

int md(int num,int modulo)
{
    num=num%modulo;
    if(num<0)num=num+modulo;
    return num;
}

void print(vector<int> A)
{
    printf("%i\n",A.size());
    for(auto k:A)printf("%i ",k);printf("\n");
    exit(0);
}
void construct_test()
{
    vector<int> A={};
    for(int i=1;i<=n;i++)
        if(md(inp[i].first,2)==md(inp[i].second,2))A.push_back(i);

    if(A.size()!=0&&A.size()!=n)print(A);

    if(A.size()==0)
    {
        for(int i=1;i<=n;i++)
            inp[i].first++;

        for(int i=1;i<=n;i++)A.push_back(i);
    }

    A={};
    for(int i=1;i<=n;i++)
        if(md(inp[i].first,2)==1)A.push_back(i);

    if(A.size()!=0&&A.size()!=n)print(A);

    if(A.size()==n)
    {
        for(int i=1;i<=n;i++)
            inp[i].first++,inp[i].second++;
    }

    for(int i=1;i<=n;i++)
        inp[i].first=inp[i].first/2,inp[i].second=inp[i].second/2;

    construct_test();
}

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    construct_test();
    return 0;
}