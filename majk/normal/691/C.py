S=input()
beg = 0
end = len(S)

while beg < end and S[beg] == '0':
    beg += 1

if '.' in S:
    while beg < end and S[end-1] == '0':
        end -= 1

    if beg < end and S[end-1] == '.':
        end -= 1

if '.' in S:
    i=S.index('.')

if beg == end:
    print('0')
elif '.' in S and i < end:
    if i == beg and end-beg == 2:
        print("%sE-1" % S[beg+1])
    elif i == beg+1:
        print(S[beg:end])
    elif i > beg+1:
        print("%s.%s%sE%d" % (S[beg], S[beg+1:i], S[i+1:end], i-beg-1))
    else:
        c = -1
        beg += 1
        while beg < end and S[beg] == '0':
            beg += 1
            c -= 1

        print("%s%s%sE%d" % (S[beg], '.' if end-beg > 1 else '', S[beg+1:end], c))
elif end-beg == 1:
    print(S[beg])
else:
    l=end-beg
    while beg < end and S[end-1] == '0':
        end -= 1
    print("%s%s%sE%d" % (S[beg], '.' if end-beg > 1 else '', S[beg+1:end], l-1))