#include<bits/stdc++.h>
using namespace std;
int a[100];
int s=0;
int n;
vector<int> p;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    int c=a[0];
    p.push_back(0);
    for(int i=1;i<n;i++) {
        if(a[i]*2<=a[0]){
            p.push_back(i);
            c+=a[i];
        }
    }
    if(c*2>s) {
        printf("%d\n",p.size());
        for(int i=0;i<p.size();i++) printf("%d ",p[i]+1);
        return 0;
    }
    printf("0\n");
    return 0;
}