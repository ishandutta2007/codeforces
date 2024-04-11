#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

char ch[100010];
vector <char> v;

int main()
{
    //freopen("input.txt","r",stdin);
    gets(ch);
    int i,l=0;
    for(i=0;ch[i];i++){
        if(!v.empty() && v.back()==ch[i])v.pop_back();
        else v.push_back(ch[i]);
    }
    printf("%s",v.empty()?"YES":"NO");
    return 0;
}