/*
 * @Author: BilyHurington
 * @Date: 2020-05-01 22:40:42
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-01 22:58:27
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int T,n;
bool check(int mid){
    int sum=n-mid-1,num=1;
    for(int i=mid;i>=1;i--){
        int x=min(sum/i,num);
        num+=x;
        sum-=i*x;
    }
    if(!sum) return 1;
    return 0;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int l=1,r=min(1000,n-1),mid;
        while(l<r){
            mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
        int sum=n-l-1,num=1;
        for(int i=l;i>=1;i--){
            int x=min(sum/i,num);
            num+=x;
            printf("%d ",x);
            sum-=i*x;
        }   
        printf("\n");
    }
    return 0;
}