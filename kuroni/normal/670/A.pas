var n : integer;
begin
    read(n);
    case (n mod 7) of
        0: write(2*(n div 7),' ', 2*(n div 7));
        1: write(2*(n div 7),' ', 2*(n div 7) + 1);
        2,3,4,5: write(2*(n div 7),' ', 2*(n div 7) + 2);
        6: write(2*(n div 7) + 1,' ', 2*(n div 7) + 2);
    end;
end.