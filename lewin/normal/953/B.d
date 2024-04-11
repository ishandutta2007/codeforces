module main;

import std.c.stdio;
import std.algorithm;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(string[] argv)
{
    int n;
    scanf("%d", &n);
    auto arr = new int[n];
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    sort(arr);

    int g = 0;
    for (int i = 1; i < n; i++) {
        g = gcd(arr[i] - arr[i-1], g);
    }

    int ret = 0;
    for (int i = 1; i < n; i++) {
        ret += (arr[i] - arr[i-1]) / g - 1;
    }

    printf("%d\n", ret);
    return 0;
}