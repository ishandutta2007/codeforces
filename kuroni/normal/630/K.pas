var n, ans: int64;
    i: longint;
begin
    read(n);
    ans := (n div 210)*48;
    for i := 1 to (n mod 210) do if ((((i mod 2 <> 0) and (i mod 3 <> 0)) and (i mod 5 <> 0)) and (i mod 7 <> 0)) then inc(ans);
    write(ans);
end.