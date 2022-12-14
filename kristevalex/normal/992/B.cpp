#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long no, mo, r, l, ans = 0, bouth;


long long NOD (long long x, long long y)
    {
    if (x == 0) return y;
    if (y == 0) return x;
    if (x == 1 || y == 1) return 1;
    if (!(x&1) && !(y&1)) return 2* NOD(x/2, y/2);
    if (!(x&1)) return NOD(x/2, y);
    if (!(y&1)) return NOD(x, y/2);
    if (x>y) return NOD(x-y, y);
    return NOD(x, y-x);
    }




int main()
    {
    FAST;

    cin >> r >> l >> no >> mo;


    if ((mo/no)*no != mo)
        {
        cout << 0;
        return 0;
        }

    mo/= no;
    if ((r/no)*no == r) r--;
    r/= no;
    r++;
    //if (l<=no) l = no;
    l/= no;

    if (l == 0)
        {
        cout << 0;
        return 0;
        }
    //if (r == 0) r = 1;


    long long tmp, tmp2;

    long long size_ = sqrt(mo);
    //cout << size_ << endl;
    /*if (l < size_)
    for (long long i = r; i <= l; i++)
        {
        //cout << i << endl;

        if ((mo/i)*i == mo)
            if (r <= (mo/i) && l >= (mo/i))
                if (NOD(i, mo/i) == 1) {ans++; /*cout << i << endl;*///}
        //}

    tmp = mo/l + 1;
    if ((mo/l)*l == mo) tmp--;
    //l = mo/r;
    //r = tmp;

    //cout << tmp;

    if (l>=size_ && r<=size_)
    for (long long i = max(r, tmp); i <= size_; i++)
        {
        //cout << i << endl;

        if ((mo/i)*i == mo)
            if (r <= (mo/i) && l >= (mo/i))
                if (NOD(i, mo/i) == 1) {ans++; /*cout << i << endl;*/}
        }


    ans*=2;



    if (size_*size_ == mo && r <= size_ && l >= size_ && size_ == 1) ans = 1;

    cout << ans;

    return 0;
    }