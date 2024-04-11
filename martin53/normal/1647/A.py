def solve():
    n=int(input());

    start=2;

    if (n%3)==1:
        start=1;

    arr=[];

    while n:
        arr.append(start);
        n=n-start;
        start=3-start;

    for i in arr:
        print(i,end="");
    print();

t=int(input());

while t:
    t=t-1;

    solve();