#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
main()
{
    scanf("%d",&N);
    vector<pair<int,int> >A;
    for(;N--;)
    {
        int c;scanf("%d",&c);
        if(A.empty()||A.back().second!=c)
        {
            A.push_back(make_pair(1,c));
        }
        else A.back().first++;
    }
    int ans=0;
    for(int i=0;i+1<A.size();i++)ans=max(ans,2*min(A[i].first,A[i+1].first));
    printf("%d\n",ans);
}