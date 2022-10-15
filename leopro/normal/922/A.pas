var
  x, y: LongInt;
  ans: string;
  
begin
  ReadLn(x, y);
  ans := 'No';
  If y-x=1 then ans := 'Yes';
  If (x-y) mod 2 = 1 then ans := 'Yes';
  If y = 0 then ans := 'No';
  If (y = 1) and (x > 0) then ans := 'No';
  WriteLn(ans);
end.