#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,q,inp[nmax];

void solve()
{
    scanf("%i%i",&n,&q);

    int arr[2]={0,0};

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        arr[inp[i]]++;
    }

    for(int i=1;i<=q;i++)
    {
        int type,cur;
        scanf("%i%i",&type,&cur);

        if(type==1)
        {
            arr[inp[cur]]--;
            inp[cur]=!inp[cur];
            arr[inp[cur]]++;
        }
        else
        {
            if(cur<=arr[1])printf("1\n");
            else printf("0\n");
        }
    }

}

int main()
{
    solve();

    return 0;
}