var
  a, b, tmp: Int32;
  ans: Char;
  
begin
  ReadLn(a, b);
  ans := '?';
  If a = 1 then ans := '<';
  If b = 1 then ans := '>';
  If (a = 2) and (b = 4) then ans := '=';
  If (a = 4) and (b = 2) then ans := '=';
  If a = b then ans := '=';
  If ans <> '?' then
  begin
    WriteLn(ans);
    Exit;
  end;
  If a = 3 then ans := '>';
  If b = 3 then ans := '<'; 
  If ans <> '?' then
  begin
    WriteLn(ans);
    Exit;
  end;
  If a = 2 then ans := '>';
  If b = 2 then ans := '<';
  If ans <> '?' then
  begin
    WriteLn(ans);
    Exit;
  end;
  If a < b then ans := '>' else ans := '<';
  WriteLn(ans);
end.