//
//  main.cpp
//  luckysum
//
//  Created by Sokol Kostya's MacBook on 27.10.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
long long nums[10000],h = 1;

void rec(int a, long long num);

void rec(int a, long long num)
{
    if ((a <= 11) && (a != 0))
    {
        ++h;
        nums[h - 1] = num;
    }
    if (a < 11)
    {
        for (long long i = 4; i < 8; i += 3)
        {
            rec(a + 1,num * 10 + i);
        }
    }
        
}

int main (int argc, const char * argv[])
{
    long long l,r;
    cin >> l >> r;
    nums[0] = 0;
    rec(0,0);
    sort(nums,nums + h);
    int now1;
    for (int i = 0; i < h - 1; i++) {
        if ((nums[i] < l) && (nums[i + 1] >= l)) 
        {
            now1 = i + 1;
        }
    }
    //for (int i = 0; i < 10; i++) cout << nums[i] << endl;
    long long ans = (min(nums[now1],r) - l + 1) * nums[now1];
    int now = now1;
    for (int i = now1 + 1; nums[i] <= r; i++){
        ans += (nums[i] - nums[i - 1]) * nums[i];
        now = i;
    }
    if (nums[now] < r)
    {
        ++now;
        ans += (r - nums[now - 1]) * nums[now];
    }
    cout << ans;
    return 0;
}