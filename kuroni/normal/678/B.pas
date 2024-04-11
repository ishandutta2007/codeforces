var y, ans, kek: longint;
    leap, temp: boolean;

function CheckLeap(a: longint): boolean;
begin
     if (a mod 4 <> 0) or ((a mod 100 = 0) and (a mod 400 <> 0)) then CheckLeap := False
     else CheckLeap := True;
end;

begin
  kek := 2;
  read(y);
  if (y mod 4 <> 0) or ((y mod 100 = 0) and (y mod 400 <> 0)) then leap := False
  else leap := True;
  ans := y + 1;
  temp := False;
  while temp = False do
  begin
    if CheckLeap(ans) = False then inc(kek) else inc(kek,2);
    if (kek mod 7 = 2) and (CheckLeap(ans) = leap) then temp := True else inc(ans);
  end;
  write(ans);
end.