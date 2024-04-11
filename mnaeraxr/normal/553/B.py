def calc(n, k):
    if n == 1:
        print(1)
    else:
        #n, k = map(int,input().split())
        tot = [0] * (n + 1)
        tot[n] = 1
        tot[n - 1] = 1
        tot[n - 2] = 2

        for i in range(n - 3, -1, -1):
            tot[i] = tot[i + 1] + tot[i + 2]

        def mPrint(a, b):
            #for i in range(a + 1, b + 1):
            #    print(i, end = " ")
            #print(a, end = " " )
            print(b, end = " ")
            for i in range(a, b):
                print(i, end = " ")

        last = 0
        for i in range(n):
            #print(k, tot[i + 1])
            if k <= tot[i + 1]:
                mPrint(last + 1, i + 1)
                last = i + 1
            else:
                k -= tot[i + 1]
        print()

n, k = map(int,input().split())
calc(n, k)