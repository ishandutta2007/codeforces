var n, cnt, a, i: longint;
begin
    read(n);
    for i := 1 to n do
    begin
        read(a);
        inc(cnt,ord(a = 0));
    end;
    if (((n = 1) and (cnt = 0)) or ((n <> 1) and (cnt = 1))) then write('YES') else write('NO');
end.