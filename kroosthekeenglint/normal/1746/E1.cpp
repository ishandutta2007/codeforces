#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
vector<int> rest_ans;
vector<int> guess[4];
vector<int> new_guess[4];
char res1[105];
char res2[105];
char res3[105]; 
void output(vector<int> &v)
{
    int i;
    for (i=0;i<(int)v.size();i++)
    {
        printf(" %d",v[i]);
    }
}
void try_query_3()
{
    int x = rest_ans[0];
    int y = rest_ans[1];
    int z = rest_ans[2];
    rest_ans.clear();
    printf("? 1 %d\n",x);
    fflush(stdout);
    scanf("%s",res1);
    if (res1[0] == 'Y')
    {
        printf("! %d\n", x);
        fflush(stdout);
        scanf("%s", res2);
        if (res2[1] == ')')
        {
            exit(0);
        }
        printf("? 1 %d\n",y);
        fflush(stdout);
        scanf("%s", res2);
        if (res2[0] == 'Y')
        {
            printf("! %d\n",y);
        }
        else
        {
            printf("! %d\n",z);
        }
        fflush(stdout);
        exit(0);
    }
    //? x : NO
    printf("? 1 %d\n",x);
    fflush(stdout);
    scanf("%s",res1);
    if (res1[0] == 'Y')
    {
        printf("! %d\n", x);
        fflush(stdout);
        scanf("%s", res2);
        if (res2[1] == ')')
        {
            exit(0);
        }
        printf("? 1 %d\n",y);
        fflush(stdout);
        scanf("%s", res2);
        if (res2[0] == 'Y')
        {
            printf("! %d\n",y);
        }
        else
        {
            printf("! %d\n",z);
        }
        fflush(stdout);
        exit(0);
    }
    rest_ans.push_back(y);
    rest_ans.push_back(z);
}
void try_query()
{
    int i;
    for (i=0;i<(int)rest_ans.size();i++)
    {
        guess[i%2].push_back(rest_ans[i]);
    }
    printf("? %u",guess[0].size());
    output(guess[0]);
    printf("\n");
    fflush(stdout);
    scanf("%s",res1);
    if (res1[0] == 'N')
    {
        swap(guess[0],guess[1]);
    }
    for (;guess[0].size() + guess[1].size() > 3u;)
    {
        new_guess[0].clear();
        new_guess[1].clear();
        new_guess[2].clear();
        new_guess[3].clear();
        for (i=0;i<(int)guess[0].size();i++)
        {
            new_guess[i%2].push_back(guess[0][i]);
        }
        for (i=0;i<(int)guess[1].size();i++)
        {
            new_guess[3-i%2].push_back(guess[1][i]);
        }
        printf("? %u", new_guess[0].size() + new_guess[2].size());
        output(new_guess[0]);
        output(new_guess[2]);
        printf("\n");
        fflush(stdout);
        scanf("%s",res1);
        if (res1[0] == 'N')
        {
            swap(new_guess[0],new_guess[1]);
            swap(new_guess[2],new_guess[3]);
        }
        new_guess[3].clear();
        guess[0].clear();
        guess[1].clear();
        for (i=0;i<(int)new_guess[0].size();i++)
        {
            guess[0].push_back(new_guess[0][i]);
        }
        for (i=0;i<(int)new_guess[2].size();i++)
        {
            guess[0].push_back(new_guess[2][i]);
        }
        for (i=0;i<(int)new_guess[1].size();i++)
        {
            guess[1].push_back(new_guess[1][i]);
        }
    }
    rest_ans.clear();
    for (i=0;i<(int)guess[0].size();i++)
    {
        rest_ans.push_back(guess[0][i]);
    }
    for (i=0;i<(int)guess[1].size();i++)
    {
        rest_ans.push_back(guess[1][i]);
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++)
    {
        rest_ans.push_back(i);
    }
    for (;rest_ans.size()>3;)
    {
        try_query();
    }
    if (rest_ans.size() == 3)
    {
        try_query_3();
    }
    for (i=0;i<(int)rest_ans.size();i++)
    {
        printf("! %d\n",rest_ans[i]);
        fflush(stdout);
        scanf("%s",res1);
        if (res1[1] == ')')
        {
            break;
        }
    }
    return 0;
}