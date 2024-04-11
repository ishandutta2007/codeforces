var n, i, j: longint;
    ans: boolean;
    
begin
    read(n);
    ans := False;
    for i := 0 to (n div 1234567) do
        for j := 0 to ((n - 1234567 * i) div 123456) do
        if (n - 1234567 * i - 123456 * j) mod 1234 = 0 then ans := True;
    if ans then write('YES') else write('NO');
end.