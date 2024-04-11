def solve():
    n, k = map(int, input().split(' '))
    inp = list(map(int, input().split(' ')))

    pref=[];

    sum=0;

    for i in range(n):
        sum=sum+inp[i];
        pref.append(sum);

    if k<n:
        MX=0;

        for i in range(k-1,n):
            cur=pref[i];

            if i>=k:
                cur=cur-pref[i-k];

            if MX<cur:
                MX=cur;

        return MX+k*(k-1)//2;


    outp=0;

    for i in range(n):
          outp=outp+i+inp[i];

    k=k-n;

    outp=outp+k*n;

    return outp;

t=int(input());

while t:
    t=t-1;

    print(solve());