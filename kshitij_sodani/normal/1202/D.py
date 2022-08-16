for _ in range(int(input())):
    n=int(input())
    ind=2

    while True:
        if (ind*(ind-1))//2>n:
            ind-=1
            break
        ind+=1
    st="1"+"3"*2+"7"*(n-(ind*(ind-1))//2)+"3"*(ind-2)+"7"
    print(st)