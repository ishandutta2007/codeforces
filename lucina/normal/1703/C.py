for _ in range(int(input())):
    n = int(input())
    x = [int(u) for u in input().split()]
    for i in range(n):
        q, w = input().split()
        cur = x[i]
        for j in range(int(q)):
            cur += 1 if w[j] == "D" else -1
        
        print(cur % 10, end = ' ')
    print()