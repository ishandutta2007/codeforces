#include<cstdio>
#include<algorithm>

using namespace std;

const int MaxN=100010;

int n,m,x,y;

struct node
{
    int size,from;
}A[MaxN],B[MaxN];

bool cmp(node A,node B)
{
    return A.size<B.size;
}

int ans;
int getA[MaxN],getB[MaxN];

int main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&A[i].size);
        A[i].from=i;
    }
    sort(A+1,A+n+1,cmp);
    for (int i=1;i<=m;++i)
    {
        scanf("%d",&B[i].size);
        B[i].from=i;
    }
    sort(B+1,B+m+1,cmp);
    int j=1;
    for (int i=1;i<=n;++i)
    {
        if (j<=m)
            while (A[i].size-x>B[j].size)
            {
                ++j;
                if (j>m) break;
            }
        if (j<=m)
            if (A[i].size+y>=B[j].size)
            {
                ++ans;
                getA[ans]=A[i].from;
                getB[ans]=B[j].from;
                ++j;
            }
    }
    printf("%d\n",ans);
    for (int i=1;i<=ans;++i)
        printf("%d %d\n",getA[i],getB[i]);
    return 0;
}