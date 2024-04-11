//
//  main.cpp
//  beforeexam
//
//  Created by Sokol Kostya's MacBook on 14.10.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int a[100],b[100];
bool bl[100];

int main (int argc, const char * argv[])
{
    double mn = 1000, mx = -1;
    int n,k,num,q;
    scanf("%d%d",&n,&k);
    num = n / k;
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    scanf("%d",&q);
    for (int i = 0; i < q; i++){
        int sum = 0;
        for (int j = 0; j < num; j++){
            int now;
            scanf("%d",&now);
            --now;
            sum += a[now];
            bl[now] = true;
        }
        //cout << sum << endl;
        double now = sum * 1.0 / num;
        mn = min(mn,now);
        mx = max(mx,now);
    }
    int h = 0;
    for (int i = 0; i < n; i++){
        if (bl[i] == false) {
            b[h] = a[i];
            ++h;
        }
    }
    sort(b,b + h);
   /* for (int i = 0; i < h; i++) cout << b[i] << " ";
    cout << endl;*/
    //cout << h - n + k * num << endl;
    if (h - n + k * num >= num) {
        int sum = 0;
        for (int j = 0; j < num; j++){
            sum += b[j];
        }
        double now = sum * 1.0 / num;
        mn = min(mn,now);
        sum = 0;
        for (int j = 0; j < num; j++){
            sum += b[h - 1 - j];
        }
        now = sum * 1.0 / num;
        mx = max(mx,now);
    }
    cout.precision(20);
    cout << mn << " " << mx;
    return 0;
}