var a,b,c : int64;
begin
    read(a,b,c);
    if c = 0 then if b = a then write('YES') else write('NO')
    else
    if ((b - a) mod c = 0) and ((b - a) * c >= 0) then write('YES') else write('NO');
    readln;
    readln;
end.