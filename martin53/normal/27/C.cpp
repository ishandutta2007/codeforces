#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,inp[nmax];
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

vector<int> now={};
now.push_back(1);
for(int i=2;i<=n;i++)
    if(inp[now[now.size()-1]]!=inp[i])now.push_back(i);

int SZ=now.size();

for(int i=1;i+1<SZ;i++)
    if((inp[now[i-1]]<inp[now[i]]&&inp[now[i]]>inp[now[i+1]])||(inp[now[i-1]]>inp[now[i]]&&inp[now[i]]<inp[now[i+1]]))
    {
        printf("3\n%i %i %i\n",now[i-1],now[i],now[i+1]);
        return 0;
    }
printf("0\n");
return 0;
}