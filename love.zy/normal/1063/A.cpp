#include<bits/stdc++.h>
#define maxn 123456

using namespace std;
char s[maxn];
int n;

int main(){
    cin >> n;
    scanf("%s",s);
    sort(s,s+n);
    printf("%s\n",s);
    return 0;
}