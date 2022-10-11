var s: ansistring;
    d, i, j: longint;
    ans: int64;
begin
  ans := 1;
  readln(s);
  for i := 1 to length(s) do
  begin
    d := ord(s[i]);
    if d in [48..57] then dec(d,48) else if d in [65..90] then dec(d,55) else if
    d in [97..122] then dec(d,61) else if d = 45 then d := 62 else d := 63;
    for j := 1 to 6 do
    begin
      if d mod 2 = 0 then ans := (3*ans) mod 1000000007;
      d := d div 2;
    end;
  end;
  write(ans);
end.