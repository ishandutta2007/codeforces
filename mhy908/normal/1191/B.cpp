#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
pair<int, char> a[5];
int main()
{
    scanf("%1d %c", &a[1].first, &a[1].second);
    scanf("%1d %c", &a[2].first, &a[2].second);
    scanf("%1d %c", &a[3].first, &a[3].second);
    sort(a+1, a+4);
    if(a[1].second==a[2].second&&a[2].second==a[3].second){
        if(a[1].first==a[2].first&&a[2].first==a[3].first){
            printf("0");
            return 0;
        }
        if(a[1].first+1==a[2].first&&a[2].first+1==a[3].first){
            printf("0");
            return 0;
        }
    }
    if(a[1].second==a[2].second){
        if(a[1].first+2>=a[2].first){
            printf("1");
            return 0;
        }
    }
    if(a[1].second==a[3].second){
        if(a[1].first+2>=a[3].first){
            printf("1");
            return 0;
        }
    }
    if(a[2].second==a[3].second){
        if(a[2].first+2>=a[3].first){
            printf("1");
            return 0;
        }
    }
    printf("2");
}